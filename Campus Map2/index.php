<!DOCTYPE html>
<html lang="en">
<head>
    <link href="https://cdn.jsdelivr.net/npm/bootstrap@5.0.2/dist/css/bootstrap.min.css" rel="stylesheet" integrity="sha384-EVSTQN3/azprG1Anm3QDgpJLIm9Nao0Yz1ztcQTwFspd3yD65VohhpuuCOmLASjC" crossorigin="anonymous">
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Campus Map</title>
    <link rel="stylesheet" href="style.css">
    <script src="https://cdn.jsdelivr.net/npm/mousetrap@1.6.5/mousetrap.min.js"></script>
</head>
<body>
    <h1>Campus Map</h1>
    <div class="main-container">
        <div class="room-info m-3"  aria-labelledby="controls-heading">
            <div class="controls">
                <h3>Controls</h3>
                <label for="start">Start Position:</label>
                <input type="text" id="start" placeholder="e.g., A1" onfocusout="highlightCell('start')" aria-describedby="start-desc">
                <span id="start-desc" class="visually-hidden">Enter the starting position in the format A1 to J10.</span>
                <label for="end">End Position:</label>
                <input type="text" id="end" placeholder="e.g., J10" onfocusout="highlightCell('end')" aria-describedby="end-desc">
                <span id="end-desc" class="visually-hidden">Enter the ending position in the format A1 to J10.</span>
                <button onclick="handleFindPath()" id="findpath" aria-label="Find Path">Find Path</button>
                <script>
                    Mousetrap.bind('alt+s', function() {
                        document.getElementById('findpath').click();
                    });
                </script>
                <audio id="audio" src="select.mp3"></audio>
                <audio id="audio1" src="select1.mp3"></audio>
                <audio id="audio2" src="select2.mp3"></audio>
                <audio id="audio3" src="select3.mp3"></audio>
                <audio id="audio4" src="select4.mp3"></audio>
                <audio id="audio5" src="select5.wav"></audio>
                <audio id="audio6" src="select6.wav"></audio>
                <audio id="audio7" src="select7.mp3"></audio>
                <p id="pathLabel">Path: </p>
                <button id="speechMuteButton" onclick="toggleSpeechMute()" aria-label="Mute Speech">Mute Speech</button>
                <p><b>Alt + A</b> (Add New Classroom)</p>
                <p><b>Alt + S</b> (Find Path)</p>
                <p><b>Shift + S</b> (Save current Route)</p>
            </div>
        </div>
        <div class="grid-container" id="grid" aria-labelledby="building-colors-heading"></div>
        <div class="room-info" aria-labelledby="building-colors-heading">
            <h3>Building Colors</h3>
            <?php
            include 'connect.php';
            $sql = "SELECT * FROM building";
            $result = mysqli_query($conn, $sql);

            $colors = [
                '#4477AA', // Blue (Teaching Complex 2)
                '#EE6677', // Red (Campus IT Services)
                '#228833', // Green (Faculty of Law)
                '#CCBB44', // Yellow (Teaching Complex 1 - changed to mustard)
                '#AA3377', // Purple (Faculty of Medicine)
                '#BBBBBB', // Gray (Faculty of Social Sciences)
                '#66CCEE', // Cyan (Faculty of Humanities)
                '#EE9933'
            ];
            $colorIndex = 0;
            while ($row = mysqli_fetch_assoc($result)) :
            ?>
                <div class="legend-item">
                    <span class="color-box" style="background-color: <?= $colors[$colorIndex % count($colors)] ?>" aria-hidden="true"></span>
                    <?= htmlspecialchars($row['building_name']) ?>
                </div>
            <?php 
                $colorIndex++;
            endwhile;
            mysqli_close($conn);
            ?>
        </div>
        <div class="room-info" aria-labelledby="rooms-heading">
            <h3>Rooms at this location</h3>
            <div id="roomDetails">
                <p>Click on a cell or enter coordinates to see room information</p>
            </div>
            <div class="favorites-section">
                <h3>Saved Routes</h3>
                <button class="btn btn-primary mb-2" id="save" onclick="saveFavorite()" aria-label="Save Current Route">Save Current Route</button>
                <script>
                    Mousetrap.bind('shift+s', function() {
                        document.getElementById('save').click();
                    });
                </script>
                <select id="favoritesList" class="form-select" onchange="loadFavorite()" aria-label="Saved Routes List">
                    <option value="">Select a saved route</option>
                </select>
                <button class="btn btn-primary mt-3" onclick="showActivityReport()" id="report" aria-label="Generate Activity Report">Generate Activity Report</button>
            </div>
        </div>
    </div>
    <div class="container my-5">
        <h4>Classroom Table</h4>
        <button class="btn btn-primary my-3" onclick="openAddClassroomModal()" id="addClassroom" aria-label="Add Classroom">Add Classroom</button>
        <script>
            Mousetrap.bind('alt+a', function() {
                document.getElementById('addClassroom').click();
            });
        </script>
        <div class="mb-3">
            <div class="input-group">
                <input type="text" id="search" class="form-control" placeholder="Search by Room Code" aria-label="Search by Room Code">
                <button class="btn btn-primary pt-2" onclick="fetchClassrooms(1)" id="hi" aria-label="Search">Search</button>
            </div>
        </div>
        <table class="table table-bordered table-hover" aria-label="Classroom Table">
            <thead class="thead-dark">
                <tr>
                    <th>Building Name</th>
                    <th>Room Code</th>
                    <th>Capacity</th>
                    <th>Availability</th>
                    <th>Action</th>
                </tr>
            </thead>
            <tbody id="classroomTable"></tbody>
        </table>
        <div id="pagination" class="mt-3" aria-label="Pagination"></div>
        <script>
            function fetchClassrooms(page = 1) {
                const search = document.getElementById('search').value;
                const xhr = new XMLHttpRequest();
                xhr.open('GET', `fetch_classrooms.php?search=${encodeURIComponent(search)}&page=${page}`, true);
                xhr.onload = function () {
                    if (this.status === 200) {
                        const response = JSON.parse(this.responseText);
                        document.getElementById('classroomTable').innerHTML = response.tableRows;
                        document.getElementById('pagination').innerHTML = response.pagination;
                    }
                };
                xhr.send();
            }
            document.addEventListener('DOMContentLoaded', () => fetchClassrooms(1));
        </script>
    </div>
    <div class="container">
        <h4>Buildings</h4>
        <table class="table table-bordered table-hover" aria-label="Buildings Table">
            <thead class="thead-dark">
                <tr>
                    <th>Building Name</th>
                    <th>Location</th>
                    <th>Number of Floors</th>
                    <th>Action</th>
                </tr>
            </thead>
            <tbody>
                <?php
                include 'connect.php';
                $sql = "SELECT building_id, building_name, location, number_of_floors FROM building";
                $result = mysqli_query($conn, $sql);
                if (mysqli_num_rows($result) > 0) {
                    while ($row = mysqli_fetch_assoc($result)) {
                        $building_id = $row['building_id'];
                        echo "<tr>";
                        echo "<td>" . $row['building_name'] . "</td>";
                        echo "<td>" . $row['location'] . "</td>";
                        echo "<td>" . $row['number_of_floors'] . "</td>";
                        echo "<td><button class='btn btn-primary' data-bs-toggle='modal' data-bs-target='#classroomModal' onclick='loadClassrooms($building_id)' id='cs'aria-label='Show Classrooms for " . htmlspecialchars($row['building_name']) . "'>Show Classrooms</button></td>";
                        echo "</tr>";
                    }
                } else {
                    echo "<tr><td colspan='4'>No buildings found.</td></tr>";
                }
                mysqli_close($conn);
                ?>
            </tbody>
        </table>
    </div>
    <div class="modal fade" id="addClassroomModal" tabindex="-1" aria-labelledby="addClassroomModalLabel" aria-hidden="true">
        <div class="modal-dialog">
            <div class="modal-content">
                <div class="modal-header">
                    <h5 class="modal-title" id="addClassroomModalLabel">Add New Classroom</h5>
                    <button type="button" class="btn-close" data-bs-dismiss="modal" aria-label="Close"></button>
                </div>
                <div class="modal-body">
                    <form id="addClassroomForm">
                        <div class="mb-3">
                            <label for="building" class="form-label">Building</label>
                            <select id="building" class="form-select"></select>
                        </div>
                        <div class="mb-3">
                            <label for="roomCode" class="form-label">Room Code</label>
                            <input type="text" id="roomCode" class="form-control" required>
                            <small class="form-text text-muted">Enter a room code between A1 and J10.</small>
                        </div>
                        <div class="mb-3">
                            <label for="capacity" class="form-label">Capacity</label>
                            <input type="number" id="capacity" class="form-control" required>
                        </div>
                        <button type="button" class="btn btn-primary" onclick="addClassroom()">Add Classroom</button>
                    </form>
                </div>
            </div>
        </div>
    </div>
    <div class="modal fade" id="classroomModal" tabindex="-1" aria-labelledby="classroomModalLabel" aria-hidden="true">
        <div class="modal-dialog modal-lg">
            <div class="modal-content">
                <div class="modal-header">
                    <h5 class="modal-title" id="classroomModalLabel">Classrooms</h5>
                    <button type="button" class="btn-close" data-bs-dismiss="modal" aria-label="Close"></button>
                </div>
                <div class="modal-body">
                    <table class="table table-bordered">
                        <thead>
                            <tr>
                                <th>Room Code</th>
                                <th>Seat Capacity</th>
                                <th>Availability</th>
                            </tr>
                        </thead>
                        <tbody id="classroomTableBody"></tbody>
                    </table>
                </div>
            </div>
        </div>
    </div>
    <div class="modal fade" id="reportModal" tabindex="-1" aria-labelledby="reportModalLabel" aria-hidden="true">
        <div class="modal-dialog modal-lg">
            <div class="modal-content">
                <div class="modal-header">
                    <h5 class="modal-title" id="reportModalLabel">User Activity Report</h5>
                    <button type="button" class="btn-close" data-bs-dismiss="modal" aria-label="Close"></button>
                </div>
                <div class="modal-body">
                    <div id="activityReport" class="mb-3"></div>
                    <button class="btn btn-primary" onclick="loadActivityReport()">Refresh</button>
                </div>
            </div>
        </div>
    </div>
    <script src="script.js"></script>
    <script src="https://cdn.jsdelivr.net/npm/bootstrap@5.3.0-alpha1/dist/js/bootstrap.bundle.min.js"></script>
</body>
</html>
