<?php
 if(isset($_POST["submit"])){
 $name = $_POST["name"];
 $email = $_POST["email"];
 $username = $_POST["username"];
 $password = $_POST["password"];
 $passwordrep = $_POST["passwordrep"];
 
 require_once'dbh.php';
 require_once'functions.php';
 
 if(emptyInputSignup($name, $email,$username,$password,$passwordrep) !== false){
	 header("location: create.php?error=emptyinput"); 
	 exit();
 }
 if(invalidUid($username) !== false){
	 header("location: create.php?error=invaliduid"); 
	 exit();
 }
 if(invalidEmail($email) !== false){
	 header("location: create.php?error=invalidemail"); 
	 exit();
 }
 if(pwdMatch($password,$passwordrep) !== false){
	 header("location: create.php?error=passwordsdontmatch"); 
	 exit();
 }
 if(uidExists($conn, $username,$email) !== false){
	 header("location: create.php?error=usernametaken"); 
	 exit();
 }
 createUser($conn,$name,$email,$username,$password);
 }
 else{
 header("location: create.php"); 
 exit();
 
 }