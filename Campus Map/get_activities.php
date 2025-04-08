<?php
include 'connect.php';

header('Content-Type: application/json');

try {
    $sql = "SELECT action_type, description, created_at, user_ip 
            FROM user_activity 
            ORDER BY created_at DESC 
            LIMIT 100";
    
    $result = $conn->query($sql);
    $activities = $result->fetch_all(MYSQLI_ASSOC);
    
    foreach ($activities as &$activity) {
        $activity['created_at'] = date('Y-m-d H:i:s', strtotime($activity['created_at']));
    }
    
    echo json_encode($activities);
} catch(Exception $e) {
    http_response_code(500);
    echo json_encode(['error' => $e->getMessage()]);
}
?>