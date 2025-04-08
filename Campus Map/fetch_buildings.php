<?php
include 'connect.php';

$sql = "SELECT building_id, building_name FROM building";
$result = mysqli_query($conn, $sql);

$buildings = [];
while ($row = mysqli_fetch_assoc($result)) {
    $buildings[] = $row;
}

echo json_encode($buildings);
?>