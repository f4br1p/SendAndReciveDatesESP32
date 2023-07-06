<?php 
	
	$host = "localhost";    
	$basededatos = "centrodecolectivos";    
	$usuariodb = "root";    
	$clavedb = "";   

	$tabla_db1 = "colectivo"; 	   

	$conexion = new mysqli($host,$usuariodb,$clavedb,$basededatos);

	if ($conexion->connect_errno) {
	    echo "No es posible la conexion con la Base de Datos....";
	    exit();
	}

?>