<?php
include 'connect.php';

header('Content-Type: application/json');

$start = $_POST['start'] ?? '';
$end = $_POST['end'] ?? '';

if (empty($start) || empty($end)) {
    echo json_encode(['success' => false, 'message' => 'Missing start or end location']);
    exit;
}


$stmt = $conn->prepare("INSERT INTO favorite_routes (start_location, end_location) VALUES (?, ?)");
$stmt->bind_param("ss", $start, $end);

if ($stmt->execute()) {
    echo json_encode(['success' => true, 'id' => $stmt->insert_id]);
} else {
    echo json_encode(['success' => false, 'message' => 'Database error']);
}

$stmt->close();
$conn->close();
?>