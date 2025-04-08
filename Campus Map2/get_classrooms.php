<?php
include 'connect.php';


if (isset($_GET['building_id'])) {
    $building_id = intval($_GET['building_id']);

    
    $sql = "SELECT room_code, capacity, is_available FROM classroom WHERE building_id = $building_id";
    $result = mysqli_query($conn, $sql);

    $classrooms = [];
    if (mysqli_num_rows($result) > 0) {
        while ($row = mysqli_fetch_assoc($result)) {
            $classrooms[] = $row;
        }
    }

   
    echo json_encode($classrooms);
} else {
    echo json_encode([]);
}

mysqli_close($conn);
?>
