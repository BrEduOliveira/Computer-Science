<html>
    <head>
		<title>Controle Inventário</title>
		<script src="https://code.jquery.com/jquery-2.1.3.min.js"></script>
		<link rel="stylesheet" href="https://maxcdn.bootstrapcdn.com/bootstrap/4.0.0/css/bootstrap.min.css" integrity="sha384-Gn5384xqQ1aoWXA+058RXPxPg6fy4IWvTNh0E263XmFcJlSAwiGgFAW/dAiS6JXm" crossorigin="anonymous">
		<script src="https://maxcdn.bootstrapcdn.com/bootstrap/4.0.0/js/bootstrap.min.js" integrity="sha384-JZR6Spejh4U02d8jOt6vLEHfe/JQGiRRSQQxSfFWpi1MquVdAyjUar5+76PVCmYl" crossorigin="anonymous"></script>
    </head>
		<body>
		<?php require_once 'process.php'?>
		
		<?php 
        if(isset($_SESSION['message'])): ?>
        
        <div class="alert alert-<?=$_SESSION['msg_type']?>"> <!--recupera cor da msg para ser exibida no topo da pagina -->
            
            <?php 
                echo $_SESSION['message'];
                unset($_SESSION['message']);
            ?>
        
        </div>
        <?php endif ?>
	
        
		<div class="container">
		<?php
			$mysqli = new mysqli('localhost','root','','icc_sistema') or die(mysqli_error($mysqli));
			$result = $mysqli->query("SELECT * FROM dados2") or die(mysqli_error($mysqli));
            //pre_r($result);
           ?>
        
        
           
           <div class="row justify-content-center">
               <table class="table">
                   <thead>
                       <tr>
                           <th>Código Nota</th>
                           <th>Cliente</th>
                           <th>Código Cliente</th>
                           <th>Código Produto</th>
                           <th>Descrição Produto</th>
                           <th>Valor Unitário</th>
                           <th>Quantidade</th>
                           <th>Total</th>
                           <th>Data</th>
                           <th colspan="2">Ação</th>
                       </tr>
                   </thead>
                   <?php
                   while ($row = $result->fetch_assoc()): ?>  <!-- loop para mostrar resultados -->
                       <tr>
                           <td><?php echo $row['cod_nota']; ?></td>
                           <td><?php echo $row['cliente']; ?></td>
                           <td><?php echo $row['cod_cliente']; ?></td>
                           <td><?php echo $row['cod_produto']; ?></td>
                           <td><?php echo $row['desc_produto']; ?></td>
                           <td><?php echo $row['valor_un']; ?></td>
                           <td><?php echo $row['quantidade']; ?></td>
                           <td><?php echo $row['total']; ?></td>
                           <td><?php echo $row['data']; ?></td>
                           <td> <!-- botao editar variavel edit, botao deletar variavel delete (id = chave primaria, ou seja registros, auto-increment -->
                               <a href="index.php?edit=<?php echo $row['id']; ?>"
                                  class="btn btn-info">Editar</a>
                               <a href="process.php?delete=<?php echo $row['id'] ?>"
                                  class="btn btn-danger">Excluir</a>
                           </td>
                           
                       </tr>
                    <?php endwhile; ?>

               </table>
           </div>
           <?php
			function pre_r( $array ){
				echo '<pre>';
				print_r( $array );
                echo '</pre>';
			}
			?>
	
			<div class="row justify-content-center">
			<form action="process.php" method="POST">
			    <input type="hidden" name="id" value="<?php echo $id; ?>">
				<div class="form-group">
				<label>Codigo Nota</label>
				<input type="text" name="cod_nota" class="form-control"
				       value="<?php echo $cod_nota;  ?>" placeholder="">
				</div>
				<div class="form-group">
				<label>Cliente</label>
				<input type="text" name="cliente" class="form-control"
				      value="<?php echo $cliente; ?>" placeholder="">
				</div>
				<div class="form-group">
				<label>Codigo Cliente</label>
				<input type="text" name="cod_cliente" class="form-control"
				       value="<?php echo $cod_cliente;  ?>" placeholder="">
				</div>
				<div class="form-group">
				<label>Codigo do Produto</label>
				<input type="text" name="cod_produto" class="form-control"
				       value="<?php echo $cod_produto;  ?>" placeholder="">
				</div>
				<div class="form-group">
				<label>Descriçâo do Produto</label>
				<input type="text" name="desc_produto" class="form-control"
				       value="<?php echo $desc_produto;  ?>" placeholder="">
				</div>
				<div class="form-group">
				<label>Valor Unitário</label>
				<input type="text" name="valor_un" class="form-control"
				       value="<?php echo $valor_un; ?>" placeholder="">
				</div>
				<div class="form-group">
				<label>Quantidade</label>
				<input type="text" name="quantidade" class="form-control"
				       value="<?php echo $quantidade; ?>" placeholder="">
				</div>
				<div class="form-group">
				<label>Total</label>
				<input type="text" name="total" class="form-control"
				       value="<?php echo $total; ?>" placeholder="">
				</div>
				<div class="form-group">
				<label>Data</label>
				<input type="date" name="data" class="form-control"
				       value="<?php echo $data; ?>" placeholder="">
				</div>
				<div class="form-group">
				<?php 
                    if ($update == true):
                ?>
                    <button type="submit" class="btn btn-info" name="update">Atualizar</button>
                <?php else: ?>
				<button type="submit" class="btn btn-primary" name="salvar">Salvar</button>
				<?php endif; ?>
				</div>
			</form>
			</div>
		</body>	   
</html>
	
			