
<?php

include 'connect.php';


$search = isset($_GET['search']) ? mysqli_real_escape_string($conn, $_GET['search']) : '';
$page = isset($_GET['page']) ? (int)$_GET['page'] : 1;


$limit = 7; 
$offset = ($page - 1) * $limit;


$countSql = "SELECT COUNT(*) AS total FROM classroom 
             JOIN building ON classroom.building_id = building.building_id";

if (!empty($search)) {
    $countSql .= " WHERE classroom.room_code LIKE '%$search%'";
}

$countResult = mysqli_query($conn, $countSql);
$totalRecords = mysqli_fetch_assoc($countResult)['total'];
$totalPages = ceil($totalRecords / $limit);


$sql = "SELECT 
            classroom.classroom_id, 
            building.building_name, 
            classroom.room_code, 
            classroom.capacity, 
            classroom.is_available 
        FROM classroom 
        JOIN building 
        ON classroom.building_id = building.building_id";

if (!empty($search)) {
    $sql .= " WHERE classroom.room_code LIKE '%$search%'";
}

$sql .= " LIMIT $limit OFFSET $offset";
$result = mysqli_query($conn, $sql);


$tableRows = '';
if (mysqli_num_rows($result) > 0) {
    while ($row = mysqli_fetch_assoc($result)) {
        $tableRows .= "<tr>";
        $tableRows .= "<td>" . htmlspecialchars($row['building_name']) . "</td>";
        $tableRows .= "<td>" . htmlspecialchars($row['room_code']) . "</td>";
        $tableRows .= "<td>" . htmlspecialchars($row['capacity']) . "</td>";
        $tableRows .= "<td>" . htmlspecialchars($row['is_available'] ? 'Yes' : 'No') . "</td>";
        $tableRows .= "<td><button class='btn btn-primary' id='h'  onclick='highlightRoom(\"" . htmlspecialchars($row['room_code']) . "\")'>Highlight Room</button></td>";
        $tableRows .= "</tr>";
    }
} else {
    $tableRows = "<tr><td colspan='5'>No classrooms found.</td></tr>";
}


$pagination = '';
if ($totalPages > 1) {
    for ($i = 1; $i <= $totalPages; $i++) {
        $activeClass = $i === $page ? 'btn-primary' : 'btn-secondary';
        $pagination .= "<button class='btn $activeClass me-1' onclick='fetchClassrooms($i)' id='number'>$i</button>";
    }
}


echo json_encode(['tableRows' => $tableRows, 'pagination' => $pagination]);


?>
