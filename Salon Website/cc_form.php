<?php
session_start(); 

if ($_SESSION['hi']!="yes1")
{
header("Location: index.html");
}
?>
<!DOCTYPE html>
<html style="font-size: 16px;">
  <head>
  <html style="font-size: 16px;">
  <script src="https://cdn.jsdelivr.net/npm/bootstrap@5.2.0-beta1/dist/js/bootstrap.bundle.min.js" integrity="sha384-pprn3073KE6tl6bjs2QrFaJGz5/SUsLqktiwsUTF55Jfv3qYSDhgCecCxMW52nD2" crossorigin="anonymous"></script>
   <link href="https://cdn.jsdelivr.net/npm/bootstrap@5.2.0-beta1/dist/css/bootstrap.min.css" rel="stylesheet" integrity="sha384-0evHe/X+R7YkIZDRvuzKMRqM+OrBnVFBL6DOitfPri4tjfHxaWutUpFmBp4vmVor" crossorigin="anonymous">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <meta charset="utf-8">
    <meta name="keywords" content="Ready To Try?">
    <meta name="description" content="">
    <meta name="page_type" content="np-template-header-footer-from-plugin">
    <title>Cancel Appointment</title>
    <link rel="stylesheet" href="nicepage1.css" media="screen">
<link rel="stylesheet" href="pain.css" media="screen">
<link rel="stylesheet" href="home.css" media="screen">
    <script class="u-script" type="text/javascript" src="jquery.js" defer=""></script>
    <script class="u-script" type="text/javascript" src="nicepage.js" defer=""></script>
    <meta name="generator" content="Nicepage 4.2.0, nicepage.com">
    <link id="u-theme-google-font" rel="stylesheet" href="https://fonts.googleapis.com/css?family=Roboto:100,100i,300,300i,400,400i,500,500i,700,700i,900,900i|Open+Sans:300,300i,400,400i,600,600i,700,700i,800,800i">
    <link id="u-page-google-font" rel="stylesheet" href="https://fonts.googleapis.com/css?family=Roboto:100,100i,300,300i,400,400i,500,500i,700,700i,900,900i">
    
    
    <script type="application/ld+json">{
		"@context": "http://schema.org",
		"@type": "Organization",
		"name": "",
		"logo": "images/logo.png"
}</script>
    <meta name="theme-color" content="#478ac9">
    <meta property="og:title" content="Template">
    <meta property="og:type" content="website">
  </head>
  <body data-home-page="template.html" data-home-page-title="Template" class="u-body">
  <nav class="navbar navbar-expand-lg navbar-light .bg-white static-top">
  <div class="container">
    <a class="navbar-brand" href="cus_menu.php">
      <img src="images/default-logo.png" alt="..." height="96">
    </a>
    <button class="navbar-toggler" type="button" data-bs-toggle="collapse" data-bs-target="#navbarSupportedContent" aria-controls="navbarSupportedContent" aria-expanded="false" aria-label="Toggle navigation">
      <span class="navbar-toggler-icon"></span>
    </button>
    <div class="collapse navbar-collapse" id="navbarSupportedContent">
      <ul class="navbar-nav ms-auto ">
        <li class="nav-item ">
          <a class="nav-link active" aria-current="page"  href="cus_menu.php">Main Menu</a>

        </li>
        &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;
        <li class="nav-item dropdown">
          <a class="nav-link active dropdown-toggle" href="#" id="navbarDropdown" role="button" data-bs-toggle="dropdown" aria-expanded="false">
           Options
          </a>
          <ul class="dropdown-menu dropdown-menu-end" aria-labelledby="navbarDropdown">
            <li><a class="dropdown-item" href="cre_app.php">Create an appointment</a></li>
            <li><a class="dropdown-item" href="sc_form.php">See current appointment</a></li>
            <li><a class="dropdown-item" href="cc_form.php">Cancel current appointment</a></li>
       
			
          </ul>
        </li>
		 &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;
		<li class="nav-item">
          <a class="nav-link active" href="logout.php">Log Out</a>
		  </li>
      </ul>
	  
    </div>
  </div>
</nav>
    <section class="u-clearfix u-section-1" id="carousel_0d8a">
      <div class="u-clearfix u-expanded-width u-layout-wrap u-layout-wrap-1">
        <div class="u-layout">
          <div class="u-layout-row">
            <div class="u-align-left u-container-style u-image u-layout-cell u-size-30 u-image-1" data-image-width="1125" data-image-height="750">
              <div class="u-container-layout u-container-layout-1"></div>
            </div>
            <div class="u-align-center u-container-style u-grey-5 u-layout-cell u-size-30 u-layout-cell-2">
              <div class="u-container-layout u-valign-middle u-container-layout-2">
                <div align="center">
				<form action="cc_form1.php" method="POST">
				<h3> TO CANCEL YOUR APPOINTMENT</h3>
				Email:<BR><input type="text" name="email"required> 
	                 <br><br>
					 <label>Appointment (date and time):</label><br>
<input type="datetime-local" id="DT" name="DT">

					<br><br>
					
					 <input type="submit" value="CANCEL THE APPOINTMENT ">
					</form>
</div>
              <p class="u-text u-text-grey-40 u-text-3"></p>
              </div>
            </div>
          </div>
        </div>
      </div>
    </section>
 <footer style="background-color: pink;">
    <div class="container p-4">
      <div class="row">
        <div class="col-lg-6 col-md-12 mb-4">
          <h5 class="mb-3" style="letter-spacing: 2px; color: #818963;">Location</h5>
          <p>
            Lot 51 Brezy Hill Halton<br>
			St.Philip
			<br>BB180 10
			<br><br>ShapesBySade246@gmail.com
          </p>
        </div>
        <div class="col-lg-3 col-md-6 mb-4">
          <h5 class="mb-3" style="letter-spacing: 2px; color: #818963;">Links</h5>
          <ul class="list-unstyled mb-0">
            <li class="mb-1">
              <a href="https://www.instagram.com/shapesbysade246/" style="color:purple;">Instagram</a>
            </li>
            <li class="mb-1">
              <a href="https://www.tiktok.com/@shapesbysade246?is_from_webapp=1&sender_device=pc" style="color: purple;">TikTok</a>
            </li>
            <li class="mb-1">
              <a href="#!" style="color: #4f4f4f;"></a>
            </li>
            <li>
              <a href="#!" style="color: #4f4f4f;"></a>
            </li>
          </ul>
        </div>
        <div class="col-lg-3 col-md-6 mb-4">
          <h5 class="mb-1" style="letter-spacing: 2px; color: #818963;">Opening hours</h5>
          <table class="table" style="color: White; border-color: #666;">
            <tbody>
              <tr>
                <td>Mon - Fri:</td>
                <td>8am - 9pm</td>
              </tr>
              <tr>
                <td>Sat - Sun:</td>
                <td>8am - 1am</td>
              </tr>
            </tbody>
          </table>
        </div>
      </div>
    </div>
    <div class="text-center p-3" style="background-color: rgba(0, 0, 0, 0.2);">
      © 2020 Copyright:
      <a class="text-dark" href="https://mdbootstrap.com/">MDBootstrap.com</a>
    </div>
    <!-- Copyright -->
  </footer>
        
  </body>
</html>