<?php
include 'connect.php';

$location = $_GET['location'] ?? '';

if (empty($location)) {
    echo json_encode([]);
    exit;
}


$sql = "SELECT c.room_code, c.capacity, c.is_available, b.building_name 
        FROM classroom c
        JOIN building b ON c.building_id = b.building_id
        WHERE c.room_code = ?";

$stmt = mysqli_prepare($conn, $sql);
mysqli_stmt_bind_param($stmt, "s", $location);
mysqli_stmt_execute($stmt);
$result = mysqli_stmt_get_result($stmt);

$rooms = [];
while ($row = mysqli_fetch_assoc($result)) {
    $rooms[] = $row;
}

echo json_encode($rooms);

mysqli_close($conn);
?>