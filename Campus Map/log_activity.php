<?php
include 'connect.php';

header('Content-Type: application/json');

$action = $_POST['action_type'] ?? '';
$description = $_POST['description'] ?? '';

if (empty($action) || empty($description)) {
    echo json_encode(['success' => false]);
    exit;
}


$user_ip = $_SERVER['REMOTE_ADDR'];
$user_agent = substr($_SERVER['HTTP_USER_AGENT'], 0, 255);

try {
    $stmt = $conn->prepare("INSERT INTO user_activity 
        (action_type, description, user_ip, user_agent) 
        VALUES (?, ?, ?, ?)");
    $stmt->bind_param("ssss", $action, $description, $user_ip, $user_agent);
    $stmt->execute();
    echo json_encode(['success' => true]);
} catch(Exception $e) {
    error_log("Activity log error: ".$e->getMessage());
    echo json_encode(['success' => false]);
}
?>