<?php

session_start();

$mysqli = new mysqli('localhost', 'root', '','icc_sistema') or die(mysqli_error($mysqli));
$id = 0; // coloca o valor padrao da variavel id como 0
$update = false; // coloca o valor padrao da variavel update como falso
$cod_nota = '';
$cliente = '';
$cod_cliente = '';
$cod_produto = '';
$desc_produto = '';
$valor_un = '';
$quantidade = '';
$total = '';
 $data = '';

if(isset($_POST['salvar'])){
    $cod_nota = $_POST['cod_nota'];
    $cliente = $_POST['cliente'];
    $cod_cliente = $_POST['cod_cliente'];
    $cod_produto = $_POST['cod_produto'];
    $desc_produto = $_POST['desc_produto'];
    $valor_un = $_POST['valor_un'];
    $quantidade = $_POST['quantidade'];
    $total = $_POST['total'];
    $data = $_POST['data'];
    
    $mysqli->query("INSERT INTO dados2 (cod_nota, cliente, cod_cliente, cod_produto, desc_produto, valor_un, quantidade, total, data) VALUES('$cod_nota', '$cliente', '$cod_cliente', '$cod_produto', '$desc_produto', '$valor_un', '$quantidade', '$total', '$data')") or
        die($mysqli->error);
    
    $_SESSION['message'] = "Registro foi salvo"; 
    $_SESSION['msg_type'] = "success"; // coloração msg
    
    header("location: index.php");
}

if(isset($_GET['delete'])){
    $id = $_GET['delete']; //guarda a variavel delete em id
    $mysqli->query("DELETE FROM dados2 WHERE id=$id") or die($mysqli_error()); // comando do mysql para deleter um registro da database caso o valor do campo id seja igual o do varivel $id
    
    $_SESSION['message'] = "Registro foi deletado";
    $_SESSION['msg_type'] = "danger";  //coloração msg
    
    
    header("location: index.php");
}

if(isset($_GET['edit'])){
    $id = $_GET['edit'];
    $update = true;
    $result = $mysqli->query("SELECT * FROM dados2 WHERE id=$id") or die ($mysqli->error());
    if ($result->num_rows){
        $row = $result->fetch_array();
        $cod_nota = $row['cod_nota'];
        $cliente = $row['cliente'];
        $cod_cliente = $row['cod_cliente'];
        $cod_produto = $row['cod_produto'];
        $desc_produto = $row['desc_produto'];
        $valor_un = $row['valor_un'];
        $quantidade = $row['quantidade'];
        $total = $row['total'];
        $data = $row['data'];
    }
}

if (isset($_POST['update'])){ // verifica se o botao update foi apertado
    $id = $_POST['id'];
    $cod_nota = $_POST['cod_nota'];
    $cliente = $_POST['cliente'];
    $cod_cliente = $_POST['cod_cliente'];
    $cod_produto = $_POST['cod_produto'];
    $desc_produto = $_POST['desc_produto'];
    $valor_un = $_POST['valor_un'];
    $quantidade = $_POST['quantidade'];
    $total = $_POST['total'];
    $data = $_POST['data'];
    
    $mysqli->query("UPDATE dados2 SET cod_nota='$cod_nota', cliente='$cliente', cod_cliente='$cod_cliente', cod_produto='$cod_produto', desc_produto='$desc_produto', valor_un='$valor_un', quantidade='$quantidade', total='$total', data= '$data' WHERE id=$id") or // faz a atualização dos dados com a id da db for igual o valor da variavel $id.
            die($mysqli->error);
    $_SESSION['message'] = "Registro foi atualizado";
    $_SESSION['msg_type'] = "warning";
    
    header("location: index.php");
    
} 


?>