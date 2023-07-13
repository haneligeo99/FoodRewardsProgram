<!DOCTYPE html>
<head>
	<title>Student List</title>
	<meta charset = "UTF-8">
	<link rel="stylesheet" href="https://cdn.jsdelivr.net/npm/water.css@2/out/water.css">
</head>
<html>
<body style = "font-family: Candara">

<h1 style="text-align:center;"><img src="foodicon.jpeg" alt="plate icon" class="right" width = "50" height = "50">&nbsp; Student List &nbsp;<img src="foodicon.jpeg" alt="plate icon" class="right" width = "50" height = "50"></h1>

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

$sql = "SELECT rewardsNo, name, points, email FROM Student";
$result = $conn->query($sql);

if ($result->num_rows > 0) {
  // output data of each row
  while($row = $result->fetch_assoc()) {    
	echo "$row[rewardsNo] &emsp; $row[name] ($row[points]) &emsp; $row[email] <br>";
  } 
} else {
  echo "0 results";
}
$conn->close();
?>

<br><br>
<a href="manageStudent.html">Back to Manage Students Directory</a><br>
<a href="indexx.html">Back to Main Menu</a>

</body>
</html>