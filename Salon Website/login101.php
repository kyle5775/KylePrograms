<?php
 
  $username = $_POST["uid"];
   $password = $_POST["password"];
  require_once 'dbh.php';
  require_once 'functions.php';
  if(emptyInputLogin($username,$password) !== false){
	 header("location: signin_create.php?error=emptyemptyinput"); 
	 exit();
 }
LoginUser($conn,$username,$password);
  