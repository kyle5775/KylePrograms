<?php
require_once '../dbh.php';

if (isset($_POST['sale_id'])) {
    $sale_id = $_POST['sale_id'];
    
    $sql = "SELECT saledetails.*, carparts.part_name 
            FROM saledetails 
            JOIN carparts ON saledetails.part_id = carparts.part_id 
            WHERE saledetails.sale_id = ?";
    $stmt = $conn->prepare($sql);
    $stmt->bind_param("i", $sale_id);
    $stmt->execute();
    $result = $stmt->get_result();

    $total = 0;
    $output = "<table class='table'>
                    <thead>
                        <tr>
                            <th>Part Name</th>
                            <th>Part ID</th>
                            <th>Quantity</th>
                            <th>Price Per Unit</th>
                            <th>Subtotal</th>
                        </tr>
                    </thead>
                    <tbody>";

    if ($result->num_rows > 0) {
        while ($row = $result->fetch_assoc()) {
            $subtotal = $row['quantity'] * $row['price_per_unit'];
            $total += $subtotal;
            $output .= "<tr>
                            <td>{$row['part_name']}</td>
                            <td>{$row['part_id']}</td>
                            <td>{$row['quantity']}</td>
                            <td>$" . number_format($row['price_per_unit'], 2) . "</td>
                            <td>$" . number_format($subtotal, 2) . "</td>
                        </tr>";
        }
    } else {
        $output .= "<tr><td colspan='5'>No details found</td></tr>";
    }

    $output .= "</tbody>
                <tfoot>
                    <tr>
                        <td colspan='4'><strong>Total</strong></td>
                        <td><strong>$" . number_format($total, 2) . "</strong></td>
                    </tr>
                </tfoot>
                </table>";

    echo $output;
    $stmt->close();
    $conn->close();
}
?>
