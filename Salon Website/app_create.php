<?php
	$servername = "localhost";
		$username = "root";
		$password = "";
		$dbname = "sbs";	
		
		$conn = mysqli_connect($servername, $username, $password, $dbname);
		require_once'dbh.php';
		 require_once'functions.php';
		$Fname=$_POST["Fname"];
		$num=$_POST["num"];
		$email=$_POST["email"];
		$DT=$_POST["DT"];
		$Tnails=$_POST["Tnails"];
		$TF=$_POST["TF"];
		
		
		if(AppExists($conn,$DT ) !== false){
	 header("location:cre_app.php?error=Appointmenttaken"); 
	 exit();
		}
		
		
		
		if (!$conn)
		{
			die ('Error: '. mysqli_error($conn));
		}
		
		$sql=mysqli_query($conn, "INSERT INTO appointments values('$Fname','$num','$email','$DT','$Tnails', '$TF')");
		
		if (!$sql)
{
die ('Error: '. mysqli_error($conn));
}
else
{
header("Location:thanks.php ");
}
mysqli_close($conn);


