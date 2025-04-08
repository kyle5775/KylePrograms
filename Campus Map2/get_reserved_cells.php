<?php
include 'connect.php';

$reserved = [];
$sql = "SELECT c.room_code, c.building_id 
        FROM classroom c
        JOIN building b ON c.building_id = b.building_id";
$result = mysqli_query($conn, $sql);

while ($row = mysqli_fetch_assoc($result)) {
    $reserved[$row['room_code']] = $row['building_id']; 
}

echo json_encode($reserved);
header("Cache-Control: no-cache, must-revalidate");
header("Expires: Sat, 26 Jul 1997 05:00:00 GMT");
?>