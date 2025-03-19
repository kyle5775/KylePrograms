<?php
require_once'dbh.php';
function emptyInputSignup($name, $email,$username,$password,$passwordrep){
$result;
if(empty($name)|| empty($email)||empty($username)||empty($password)||empty($passwordrep)){
	$result = true;
}
else{
	$result = false;
}
return $result;
}
function invalidUid($username){
$result;
if(!preg_match("/^[a-zA-Z0-9]*$/", $username)){
	$result = true;
}
else{
	$result = false;
}
return $result;
}
function invalidEmail($email){
$result;
if(!filter_var($email, FILTER_VALIDATE_EMAIL)){
	$result = true;
}
else{
	$result = false;
}
return $result;
}
function pwdMatch($password,$passwordrep){
$result;
if($password !== $passwordrep){
	$result = true;
}
else{
	$result = false;
}
return $result;
}
function uidExists($conn, $username, $email){
$sql = "SELECT * FROM users WHERE usersUid = ? OR usersEmail = ?;";
$stmt = mysqli_stmt_init($conn);
if(!mysqli_stmt_prepare($stmt,$sql)){
	 header("location: create.php?error=stmtfailed"); 
	 exit();
}
mysqli_stmt_bind_param($stmt, "ss",$username, $email);
mysqli_stmt_execute($stmt); 
$resultData = mysqli_stmt_get_result($stmt);
if($row = mysqli_fetch_assoc($resultData)){
	return $row;
	
}
else{
	$result = false;
	return $result;
}
mysqli_stmt_close($stmt);
}
function createUser($conn,$name, $email,$username,$password){
$sql = "INSERT INTO users (usersName,usersEmail,usersUid,usersPwd)VALUES (?,?,?,?);";
$stmt = mysqli_stmt_init($conn);
if(!mysqli_stmt_prepare($stmt,$sql)){
	 header("location: create.php?error=stmtfailed"); 
	 exit();
}
$hashedPwd = password_hash($password,PASSWORD_DEFAULT);
mysqli_stmt_bind_param($stmt, "ssss",$name, $email, $username, $hashedPwd);
mysqli_stmt_execute($stmt); 
mysqli_stmt_close($stmt);
header("location: create.php?error=none"); 
	 exit();
}
function emptyInputLogin($name,$password){
$result;
if(empty($name)|| empty($password)){
	$result = true;
}
else{
	$result = false;
}
return $result;
}
function LoginUser($conn,$username,$password){
	$uidExists = uidExists($conn, $username, $username);
	if($uidExists === false){
		header("location: signin_create.php?error=wrongLogin"); 
	 exit();
	}
	$pwdHashed = $uidExists["usersPwd"];
$checkPwd = password_verify($password, $pwdHashed);
if($checkPwd === false)
{
header("location: signin_create.php?error=wrongLogin"); 
	 exit();
}	
else if ($checkPwd === true){
	session_start();
 $_SESSION['hi'] = "yes1";
header("location: cus_menu.php"); 
	 exit();
}
}
function AppExists($conn,$DT){
$sql = "SELECT * FROM appointments WHERE DateTime = ?;";
$stmt = mysqli_stmt_init($conn);
if(!mysqli_stmt_prepare($stmt,$sql)){
	 header("location:app_create.php?error=stmtfailed"); 
	 exit();
}
mysqli_stmt_bind_param($stmt, "s",$DT);
mysqli_stmt_execute($stmt); 
$resultData = mysqli_stmt_get_result($stmt);
if($row = mysqli_fetch_assoc($resultData)){
	return $row;	
}
else{
	$result = false;
	return $result;
}
mysqli_stmt_close($stmt);
}