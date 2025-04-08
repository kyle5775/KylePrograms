<?php
include 'connect.php';

header('Content-Type: application/json');

$result = $conn->query("SELECT id, start_location, end_location FROM favorite_routes ORDER BY created_at DESC");
$favorites = [];

while ($row = $result->fetch_assoc()) {
    $favorites[] = [
        'id' => $row['id'],
        'start' => $row['start_location'],
        'end' => $row['end_location'],
        'label' => $row['start_location'] . ' to ' . $row['end_location']
    ];
}

echo json_encode($favorites);
$conn->close();
?>