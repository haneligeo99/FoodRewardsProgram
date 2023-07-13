<!DOCTYPE html>
<head>
	<title>Check Points</title>
	<meta charset = "UTF-8">
	<link rel="stylesheet" href="https://cdn.jsdelivr.net/npm/water.css@2/out/water.css">
</head>
<html>
<body style = "font-family: Candara">

<h2 style="text-align:center;"><img src="foodicon.jpeg" alt="plate icon" class="right" width = "50" height = "50">&nbsp; Check Points &nbsp;<img src="foodicon.jpeg" alt="plate icon" class="right" width = "50" height = "50"></h2>

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

$sql1 = "SELECT rewardsNo, name, points FROM Student WHERE rewardsNo = '$rewardsNo'";
$result1 = $conn->query($sql1);

if ($result1->num_rows > 0) {
  // output data of each row
  while($row = $result1->fetch_assoc()) {    
	echo "$row[rewardsNo] - $row[name] <br> TOTAL POINTS: $row[points] <br>";
  }
} else {
  echo "This RewardsNo does not exist.";
}
$conn->close();
?>

<br><br>
<a href="managePoints.html">Back to Manage Points</a> <br>
<a href="indexx.html">Back to Main Menu</a>

</body>
</html>