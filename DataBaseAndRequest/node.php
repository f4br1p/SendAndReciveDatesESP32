<?php 
include("abrir_conexion.php");?>
	<?php
	$sql="SELECT * from colectivo";
	$result=mysqli_query($conexion, $sql);
	while ($mostrar=mysqli_fetch_array($result)) {
	?>
		<?php echo ',' .$mostrar['motor1'] .','.$mostrar['motor2'].','.$mostrar['motor3'] . ',' ?>
	<?php
	}
	header("Refresh:1");
?>


