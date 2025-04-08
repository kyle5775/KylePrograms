<?php
include 'connect.php';

$building_id = (int)$_POST['building_id'];
$room_code = mysqli_real_escape_string($conn, $_POST['room_code']);
$capacity = (int)$_POST['capacity'];

$sql = "INSERT INTO classroom (building_id, room_code, capacity) VALUES ('$building_id', '$room_code', '$capacity')";
if (mysqli_query($conn, $sql)) {
    echo 'success';
} else {
    echo 'error';
}
?>