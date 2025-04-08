<?php
include 'connect.php';

$room_code = mysqli_real_escape_string($conn, $_POST['room_code']);
$sql = "SELECT COUNT(*) AS count FROM classroom WHERE room_code = '$room_code'";
$result = mysqli_query($conn, $sql);
$count = mysqli_fetch_assoc($result)['count'];

echo $count == 0 ? 'valid' : 'invalid';
?>