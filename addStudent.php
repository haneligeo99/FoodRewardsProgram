<!DOCTYPE html>
<head>
	<title>Join Rewards Program</title>
	<meta charset = "UTF-8">
	<link rel="stylesheet" href="https://cdn.jsdelivr.net/npm/water.css@2/out/water.css">
</head>
<html>
<body style = "font-family: Candara">

<h2 style="text-align:center;"><img src="foodicon.jpeg" alt="plate icon" class="right" width = "50" height = "50">&nbsp; Successfully Joined &nbsp;<img src="foodicon.jpeg" alt="plate icon" class="right" width = "50" height = "50"></h2>

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
$name = $_POST["name"];
$email = $_POST["email"];

$sql = "INSERT INTO Student (rewardsNo, name, email)
VALUES ('$rewardsNo','$name', '$email')";


if ($conn->query($sql) == TRUE) {
  echo "Thank you for joining. Remember your RewardsNo is $rewardsNo<br>";
} else {
  echo "Error: " . $sql . "<br>" . $conn->error;
}

$conn->close();
?>

<br><br>
<a href="manageStudent.html">Back to Manage Students Directory</a><br>
<a href="indexx.html">Back to Main Menu</a>

</body>
</html>
