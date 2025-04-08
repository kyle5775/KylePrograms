const grid = document.getElementById("grid");
let isSpeechMuted = false;
const speechSynth = window.speechSynthesis;
const rows = 10;
const cols = 10;
const table = [];
const startInput = document.getElementById("start");
const endInput = document.getElementById("end");
const findPathButton = document.getElementById("findPathButton");
let startLocation = null;
let endLocation = null;
let reservedCells = new Set();
const colorPalette = [
  '#4477AA',
  '#EE6677',
  '#228833',
  '#CCBB44',
  '#AA3377',
  '#BBBBBB',
  '#66CCEE',
  '#EE9933'
];
let buildingColors = {};

function fetchReservedCells() {
  fetch('get_reserved_cells.php')
    .then(response => response.json())
    .then(data => {
      reservedCells = data;
      assignBuildingColors();
      createLabeledGrid();
    })
    .catch(error => console.error("Error:", error));
}

function assignBuildingColors() {
  const uniqueBuildings = [...new Set(Object.values(reservedCells))];
  uniqueBuildings.forEach((buildingId, index) => {
      buildingColors[buildingId] = colorPalette[index % colorPalette.length];
  });
}

function highlightRoom(roomCode) {
  if (!/^[A-J](10|[1-9])$/.test(roomCode)) {
      alert("Invalid room code. Please enter a valid room code (e.g., A1, J10).");
      return;
  }
  const [row, col] = parseLocation(roomCode);
  document.querySelectorAll(".cell").forEach((cell) => cell.classList.remove("highlight"));
  table[row][col].classList.add("highlight");
  const audio = document.getElementById('audio3');
  audio.play();
}

function createLabeledGrid() {
  grid.innerHTML = '';
  table.length = 0;
  const topLeft = document.createElement("div");
  topLeft.classList.add("label");
  grid.appendChild(topLeft);
  for (let col = 0; col < cols; col++) {
    const label = document.createElement("div");
    label.classList.add("label");
    label.textContent = String.fromCharCode(65 + col);
    grid.appendChild(label);
  }
  for (let row = 0; row < rows; row++) {
    const rowLabel = document.createElement("div");
    rowLabel.classList.add("label");
    rowLabel.textContent = row + 1;
    grid.appendChild(rowLabel);
    const rowArray = [];
    for (let col = 0; col < cols; col++) {
      const cell = document.createElement("div");
      cell.classList.add("cell");
      cell.dataset.row = row;
      cell.dataset.col = col;
      const cellName = `${String.fromCharCode(65 + col)}${row + 1}`;
      if (reservedCells[cellName]) {
        cell.style.backgroundColor = buildingColors[reservedCells[cellName]];
    }
      cell.addEventListener("click", () => handleCellClick(row, col));
      grid.appendChild(cell);
      rowArray.push(cell);
    }
    table.push(rowArray);
  }
}
function handleCellClick(row, col) {
  const cellCode = `${String.fromCharCode(65 + col)}${row + 1}`;
  showRoomInfo(cellCode);
  if (!document.getElementById("start").value) {
      document.getElementById("start").value = cellCode;
      highlightCell('start');
  } else if (!document.getElementById("end").value) {
      document.getElementById("end").value = cellCode;
      highlightCell('end');
  } else {
      resetSelection();
      document.getElementById("start").value = cellCode;
      highlightCell('start');
      document.getElementById("end").value = "";
  }
}

function resetSelection() {
  document.querySelectorAll(".cell").forEach((cell) => {
    cell.classList.remove("start", "end", "path", "start-highlight", "end-highlight");
  });
  document.getElementById("pathLabel").textContent = "Path: ";
  startLocation = null;
  endLocation = null;
}

function parseLocation(location) {
  const col = location.charCodeAt(0) - 65;
  const row = parseInt(location.slice(1), 10) - 1;
  return [row, col];
}

fetchReservedCells();

function highlightPath(path) {
  path.forEach(([row, col]) => {
    table[row][col].classList.add("path");
  });
}

function updatePathLabel(path) {
  const pathLabel = document.getElementById("pathLabel");
  let pathText = "No path found!";
  let speechText = "No path could be found between these locations";

  if (path.length > 0) {
    pathText = path
      .map(([row, col]) => `${String.fromCharCode(65 + col)}${row + 1}`)
      .join(" -> "); // Keep arrows for display
    
    // Create speech version by replacing -> with then
    const speechPath = pathText.replace(/ -> /g, ' then ');
    speechText = `Path found: From ${startInput.value} to ${endInput.value}. Follow ${speechPath}`;
  }

  pathLabel.textContent = `Path: ${pathText}`;
  
  // Speak the modified version
  speakPath(speechText);
}
// Add error handling for browsers without support
if (!('speechSynthesis' in window)) {
    console.warn('Text-to-speech not supported in this browser');
    document.getElementById('speechMuteButton').disabled = true;
}


function findShortestPath(start, end) {
  const directions = [
    [0, 1],
    [1, 0],
    [0, -1],
    [-1, 0],
  ];
  const queue = [[start]];
  const visited = new Set();
  visited.add(`${start[0]},${start[1]}`);
  while (queue.length > 0) {
    const path = queue.shift();
    const [currentRow, currentCol] = path[path.length - 1];
    if (currentRow === end[0] && currentCol === end[1]) {
      highlightPath(path);
      updatePathLabel(path);
      if (path.length > 0) {
        const pathText = document.getElementById("pathLabel").textContent.replace("Path: ", "");
        fetch('log_activity.php', {
          method: 'POST',
          headers: { 'Content-Type': 'application/x-www-form-urlencoded' },
          body: `action_type=path_found&description=${encodeURIComponent(pathText)}`
        });
      }
      return;
    }
    for (const [dx, dy] of directions) {
      const newRow = currentRow + dx;
      const newCol = currentCol + dy;
      if (
        newRow >= 0 &&
        newRow < rows &&
        newCol >= 0 &&
        newCol < cols &&
        !visited.has(`${newRow},${newCol}`) &&
        !reservedCells.hasOwnProperty(`${String.fromCharCode(65 + newCol)}${newRow + 1}`)
      ) {
        visited.add(`${newRow},${newCol}`);
        queue.push([...path, [newRow, newCol]]);
      }
    }
  }
  alert("No path found!");
  updatePathLabel([]);
}

function handleFindPath() {
  document.querySelectorAll(".cell").forEach((cell) => {
    cell.classList.remove("path");
  });
  const startInput = document.getElementById("start").value.trim().toUpperCase();
  const endInput = document.getElementById("end").value.trim().toUpperCase();
  if (!startInput || !endInput) {
    alert("Please select both start and end positions!");
    return;
  }
  try {
    const start = parseLocation(startInput);
    const end = parseLocation(endInput);
    table[start[0]][start[1]].classList.add("start");
    table[end[0]][end[1]].classList.add("end");
    findShortestPath(start, end);
  } catch (e) {
    alert("Invalid cell selection!");
    console.error(e);
  }
}

function loadClassrooms(buildingId) {
  fetch(`get_classrooms.php?building_id=${buildingId}`)
      .then(response => response.json())
      .then(data => {
          const classroomTableBody = document.getElementById('classroomTableBody');
          classroomTableBody.innerHTML = '';
          if (data.length > 0) {
              data.forEach(classroom => {
                  const row = document.createElement('tr');
                  row.innerHTML = `
                      <td>${classroom.room_code}</td>
                      <td>${classroom.capacity}</td>
                      <td>${classroom.is_available ? 'Available' : 'Not Available'}</td>
                  `;
                  classroomTableBody.appendChild(row);
              });
          } else {
              classroomTableBody.innerHTML = '<tr><td colspan="3">No classrooms found.</td></tr>';
          }
      })
      .catch(error => {
          console.error('Error loading classrooms:', error);
      });
}

function highlightCell(inputId) {
  const input = document.getElementById(inputId).value.trim().toUpperCase();
  if (!/^[A-J](10|[1-9])$/.test(input)) {
      if (inputId === "start" || inputId === "end") {
          return;
      }
      alert("Invalid input. Please enter a valid cell (e.g., A1, J10).");
      return;
  }
  const [row, col] = parseLocation(input);
  if (inputId === "start") {
      document.querySelectorAll(".cell").forEach((cell) => cell.classList.remove("start-highlight"));
      table[row][col].classList.add("start-highlight");
  } else if (inputId === "end") {
      document.querySelectorAll(".cell").forEach((cell) => cell.classList.remove("end-highlight"));
      table[row][col].classList.add("end-highlight");
  }
  showRoomInfo(input);
}

function openAddClassroomModal() {
  fetchBuildings();
  const modal = new bootstrap.Modal(document.getElementById('addClassroomModal'));
  modal.show();
}

function fetchBuildings() {
  const xhr = new XMLHttpRequest();
  xhr.open('GET', 'fetch_buildings.php', true);
  xhr.onload = function () {
      if (this.status === 200) {
          const buildings = JSON.parse(this.responseText);
          const buildingSelect = document.getElementById('building');
          buildingSelect.innerHTML = buildings.map(building => `<option value="${building.building_id}">${building.building_name}</option>`).join('');
      }
  };
  xhr.send();
}

function addClassroom() {
  const buildingId = document.getElementById('building').value;
  const roomCode = document.getElementById('roomCode').value.trim().toUpperCase();
  const capacity = document.getElementById('capacity').value;
  if (!/^[A-J](10|[1-9])$/.test(roomCode)) {
    alert("Invalid room code format. Please use format like A1-J10");
    return;
  }
  const xhr = new XMLHttpRequest();
  xhr.open('POST', 'validate_room_code.php', true);
  xhr.setRequestHeader('Content-Type', 'application/x-www-form-urlencoded');
  xhr.onload = function() {
    if (this.status === 200 && this.responseText === 'valid') {
      const xhrAdd = new XMLHttpRequest();
      xhrAdd.open('POST', 'add_classroom.php', true);
      xhrAdd.setRequestHeader('Content-Type', 'application/x-www-form-urlencoded');
      xhrAdd.onload = function() {
        if (this.status === 200) {
          alert('Classroom added successfully!');
          fetchReservedCells();
          fetchClassrooms(1);
          const modal = bootstrap.Modal.getInstance(document.getElementById('addClassroomModal'));
          modal.hide();
          fetch('log_activity.php', {
            method: 'POST',
            headers: { 'Content-Type': 'application/x-www-form-urlencoded' },
            body: `action_type=classroom_added&description=${encodeURIComponent(`Added ${roomCode} (Capacity: ${capacity})`)}`
          });
        }
      };
      xhrAdd.send(`building_id=${buildingId}&room_code=${encodeURIComponent(roomCode)}&capacity=${capacity}`);
    } else {
      alert('Room code already exists or is invalid. Please use a unique code.');
    }
  };
  xhr.send(`room_code=${encodeURIComponent(roomCode)}`);
}

document.getElementById('favoritesList').addEventListener('click', function() {
  const audio = document.getElementById('audio7');
  audio.play();
});
document.getElementById('cs').addEventListener('click', function() {
  const audio = document.getElementById('audio6');
  audio.play();
});

document.getElementById('report').addEventListener('click', function() {
  const audio = document.getElementById('audio5');
  audio.play();
});

document.getElementById('findpath').addEventListener('click', function() {
  const audio = document.getElementById('audio');
  audio.play();
});
document.getElementById('addClassroom').addEventListener('click', function() {
  const audio = document.getElementById('audio1');
  audio.play();
});
document.getElementById('hi').addEventListener('click', function() {
  const audio = document.getElementById('audio2');
  audio.play();
});

function showRoomInfo(cellCode) {
  fetch(`get_rooms_at_location.php?location=${cellCode}`)
      .then(response => response.json())
      .then(data => {
          const roomDetails = document.getElementById('roomDetails');
          if (data.length > 0) {
              let html = '';
              data.forEach(room => {
                  html += `
                      <div class="room-item">
                          <strong>${room.room_code}</strong><br>
                          Building: ${room.building_name}<br>
                          Capacity: ${room.capacity}<br>
                          Status: ${room.is_available ? 'Available' : 'Not Available'}
                      </div>
                  `;
              });
              roomDetails.innerHTML = html;
          } else {
              roomDetails.innerHTML = '<p>No rooms found at this location</p>';
          }
      })
      .catch(error => {
          console.error('Error fetching room info:', error);
          document.getElementById('roomDetails').innerHTML = '<p>Error loading room information</p>';
      });
}

async function saveFavorite() {
  const start = document.getElementById('start').value.trim();
  const end = document.getElementById('end').value.trim();
  if (!start || !end) {
      alert('Please set both start and end locations');
      return;
  }
  try {
      const response = await fetch('save_favorite.php', {
          method: 'POST',
          headers: {
              'Content-Type': 'application/x-www-form-urlencoded',
          },
          body: `start=${encodeURIComponent(start)}&end=${encodeURIComponent(end)}`
      });
      const result = await response.json();
      if (result.success) {
          alert('Route saved successfully!');
          updateFavoritesList();
          const audio = document.getElementById('audio4');
  audio.play();
  fetch('log_activity.php', {
    method: 'POST',
    headers: { 'Content-Type': 'application/x-www-form-urlencoded' },
    body: `action_type=path_saved&description=${encodeURIComponent(`Saved: ${start} to ${end}`)}`
  });
      } else {
          alert(result.message || 'Error saving route');
      }
  } catch (error) {
      console.error('Error:', error);
      alert('Error saving route');
  }
}

async function updateFavoritesList() {
  try {
      const response = await fetch('get_favorites.php');
      const favorites = await response.json();
      const select = document.getElementById('favoritesList');
      select.innerHTML = '<option value="">Select a saved route</option>';
      favorites.forEach(favorite => {
          const option = document.createElement('option');
          option.value = favorite.id;
          option.textContent = favorite.label;
          option.dataset.start = favorite.start;
          option.dataset.end = favorite.end;
          select.appendChild(option);
      });
  } catch (error) {
      console.error('Error loading favorites:', error);
  }
}

function loadFavorite() {
  const select = document.getElementById('favoritesList');
  const selectedOption = select.options[select.selectedIndex];
  if (selectedOption.value) {
      document.getElementById('start').value = selectedOption.dataset.start;
      document.getElementById('end').value = selectedOption.dataset.end;
      highlightCell('start');
      highlightCell('end');
      handleFindPath();
      fetch('log_activity.php', {
        method: 'POST',
        headers: { 'Content-Type': 'application/x-www-form-urlencoded' },
        body: `action_type=path_loaded&description=${encodeURIComponent(`Loaded: ${selectedOption.dataset.start} to ${selectedOption.dataset.end}`)}`
      });
  }
}

document.addEventListener('DOMContentLoaded', updateFavoritesList);

function showActivityReport() {
  const modal = new bootstrap.Modal(document.getElementById('reportModal'));
  modal.show();
  loadActivityReport();
}

async function loadActivityReport() {
  try {
      const response = await fetch('get_activities.php');
      if (!response.ok) throw new Error(`HTTP error! ${response.status}`);
      const activities = await response.json();
      console.log('Received activities:', activities);
      const reportContainer = document.getElementById('activityReport');
      reportContainer.innerHTML = '';
      if (activities.error) {
          reportContainer.innerHTML = `<div class="alert alert-danger">${activities.error}</div>`;
          return;
      }
      if (!activities.length) {
          reportContainer.innerHTML = '<p>No activities found. Perform some actions first!</p>';
          return;
      }
      const list = document.createElement('div');
      activities.forEach(activity => {
          const item = `
              <div class="card mb-3">
                  <div class="card-body">
                      <h5 class="card-title">
                          <span class="badge ${getActionBadgeClass(activity.action_type)}">
                              ${activity.action_type.replace(/_/g, ' ')}
                          </span>
                          <small class="text-muted ms-2">
                              ${activity.created_at}
                          </small>
                      </h5>
                      <p class="card-text">${activity.description}</p>
                      ${activity.user_ip ? `<small class="text-muted">From IP: ${activity.user_ip}</small>` : ''}
                  </div>
              </div>
          `;
          list.innerHTML += item;
      });
      reportContainer.appendChild(list);
  } catch (error) {
      console.error('Error loading report:', error);
      document.getElementById('activityReport').innerHTML = `
          <div class="alert alert-danger">
              Error loading report: ${error.message}
          </div>
      `;
  }
}

function getActionBadgeClass(actionType) {
  const classes = {
      'path_found': 'bg-success',
      'classroom_added': 'bg-primary',
      'path_saved': 'bg-warning',
      'path_loaded': 'bg-info'
  };
  return `badge ${classes[actionType] || 'bg-secondary'}`;
}
function speakPath(text) {
  if (isSpeechMuted || !text) return;
  
  const utterance = new SpeechSynthesisUtterance(text);
  utterance.rate = 0.7; 
  utterance.pitch = 1;
  speechSynthesis.speak(utterance);
}

// Toggle function
function toggleSpeechMute() {
  isSpeechMuted = !isSpeechMuted;
  const button = document.getElementById('speechMuteButton');
  button.textContent = isSpeechMuted ? 'Unmute Speech' : 'Mute Speech';
  button.classList.toggle('muted', isSpeechMuted);
  if (!isSpeechMuted) speechSynth.cancel(); 
}
