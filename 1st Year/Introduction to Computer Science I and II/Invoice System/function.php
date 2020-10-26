<?php
include_once("conexao.php");

function retorna($cod_nota, $conn){
	$result_cliente = "SELECT * FROM dados WHERE cod_nota = '$cod_nota' LIMIT 1"; // seleciona dados do banco de dados quando a variavel do codigo da nota for igual ao campo codigo da nota da DB.
	$resultado_cliente = mysqli_query($conn, $result_cliente);
	if($resultado_cliente->num_rows){
		$row_cli = mysqli_fetch_assoc($resultado_cliente);
		$valores['nome_cli'] = $row_cli['nome_cli'];
		$valores['cod_cli'] = $row_cli['cod_cli'];
		$valores['data'] = $row_cli['data'];
	}else{
		$valores['nome_cli'] = '';
	}
	return json_encode($valores);
}

if(isset($_GET['cod_nota'])){
	echo retorna($_GET['cod_nota'], $conn);
}


?>
