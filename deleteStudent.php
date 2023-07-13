<!DOCTYPE html>
<head>
	<title>Delete Student</title>
	<meta charset = "UTF-8">
	<link rel="stylesheet" href="https://cdn.jsdelivr.net/npm/water.css@2/out/water.css">
</head>
<html>
<body style = "font-family: Candara">

<h2 style="text-align:center;"><img src="foodicon.jpeg" alt="plate icon" class="right" width = "50" height = "50">&nbsp; Delete Student &nbsp; <img src="foodicon.jpeg" alt="plate icon" class="right" width = "50" height = "50"></h2>

<?php
$servername = "127.0.0.1";
$username = "root";
$password = "";
$dbname = "rewards";

// Create connection
$conn = new mysqli($servername, $username, $password, $dbname);
// Check connection
if ($conn->connect_error) {
  die("Connection failed: " . $conn->connect_error);
}

$rewardsNo = $_POST["rewardsNo"];
$sql1 = "SELECT rewardsNo, name, points, email FROM Student WHERE rewardsNo = '$rewardsNo'";
$result1 = $conn->query($sql1);

if ($result1->num_rows > 0) {
  // delete row   	  
	$sql2 = "DELETE FROM Student WHERE rewardsNo = '$rewardsNo'";
	$result2 = $conn->query($sql2);
	
	$row = $result1->fetch_row();	
	echo "<b>The student below was deleted successfully:</b> <br><br>RewardsNo: " .$row[0]. 
	" <br> Name: $row[1] <br>";	 
} else {
  echo "Student does not exist!";
}

$conn->close();
?>

<br><br>
<a href="manageStudent.html">Back to Manage Students Directory</a><br>
<a href="indexx.html">Back to Main Menu</a>

</body>
</html>
