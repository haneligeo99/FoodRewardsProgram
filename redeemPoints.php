<!DOCTYPE html>
<head>
	<title>Redeem Points</title>
	<meta charset = "UTF-8">
	<link rel="stylesheet" href="https://cdn.jsdelivr.net/npm/water.css@2/out/water.css">
</head>
<html>
<body style = "font-family: Candara">

<h2>Redeem Points</h2>

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
$food = $_POST["food"];
$points = $_POST["points"];

$sql = "SELECT rewardsNo, name, points, email FROM Student WHERE rewardsNo = '$rewardsNo'";
$result = $conn->query($sql);
		$sql1 = "SELECT rewardsNo, name, points FROM Student WHERE rewardsNo = '$rewardsNo'";
		$row = $conn->query($sql1)->fetch_assoc();

if ($result->num_rows > 0) {
  // Choose food item

	//cheeseburger = points - 15
	if ($food == "1"){
		//Update Points
		$sql = "UPDATE Student SET points = points - 15 WHERE rewardsNo = '$rewardsNo'"; 
		$result = $conn->query($sql);

		//Display Points
		$sql1 = "SELECT rewardsNo, name, points FROM Student WHERE rewardsNo = '$rewardsNo'";
		$row = $conn->query($sql1)->fetch_assoc();
		echo "Food Redeemed: Cheeseburger<br> $row[name]'s points are now $row[points] <br>";
	}  

	//pizza = points - 20
	elseif ($food == "2"){
		//Update Points
		$sql = "UPDATE Student SET points = points - 20 WHERE rewardsNo = '$rewardsNo'";
		$result = $conn->query($sql);
		
		//Display Points		
		$sql1 = "SELECT rewardsNo, name, points FROM Student WHERE rewardsNo = '$rewardsNo'";
		$row = $conn->query($sql1)->fetch_assoc();
		echo "Food Redeemed: Pizza<br> $row[name]'s points are now $row[points] <br>";
	}
	
	//salad  = points - 15 
	elseif ($food == "3"){
		//Update Points
		$sql = "UPDATE Student SET points = points - 15 WHERE rewardsNo = '$rewardsNo'";
		$result = $conn->query($sql);
		
		//Display Points
		$sql1 = "SELECT rewardsNo, name, points FROM Student WHERE rewardsNo = '$rewardsNo'";
		$row = $conn->query($sql1)->fetch_assoc();
		echo "Food Redeemed: Salad <br> $row[name]'s points are now $row[points] <br>";
	}

	//Daily Special = points - 40
	elseif ($food == "4"){
		//Update Points
		$sql = "UPDATE Student SET points = points - 40 WHERE rewardsNo = '$rewardsNo'";
		$result = $conn->query($sql);

		//Display Points 
		$sql1 = "SELECT rewardsNo, name, points FROM Student WHERE rewardsNo = '$rewardsNo'";
		$row = $conn->query($sql1)->fetch_assoc();
		echo "Food Redeemed: The Daily Special. <br> $row[name]'s points are now $row[points]<br>";
	}
	else {
		echo "Invalid entry";
	}
	 
} 
else {
  echo "Student does not exist!";
}

$conn->close();
?>

<br><br>
<a href="managePoints.html">Back to Manage Points</a> <br>
<a href="indexx.html">Back to Main Menu</a>

</body>
</html>