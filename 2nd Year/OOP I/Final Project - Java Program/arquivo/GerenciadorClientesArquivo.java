package arquivo;

//Importa o package essencial para o tratamento de exceções e o package clientes
import java.io.*;
import cliente.*;

public class GerenciadorClientesArquivo implements GerenciadorClientes{
	//Método que vai receber o array de clientes e inserir os nomes no arquivo txt
	@Override	
	public void gravarClientes(Cliente[] nome, int tam) {
		BufferedWriter w = null;
		try {
			w = new BufferedWriter(new FileWriter("clientes.txt"));	
			for(int i=0; i<tam; i++) {
				w.write(nome[i].getNome());
				w.newLine();	
			}
		}catch(IOException exc) {
			System.err.println("Erro de Entrada e Saida (I/O): " + exc);
		}finally {
			try {
				if(w != null) {
					w.close();
				}
			}catch(IOException exc) {
				System.out.println("Fechando arquivo " + exc);
			}
		}
	}
	
	//Método para imprimir os nomes dos clientes contidos no arquivo clientes.txt
	@Override
	public void lerClientes() {
		String nomes;
		
		try(BufferedReader br = new BufferedReader(new FileReader("clientes.txt"))){
			while((nomes = br.readLine()) != null) {
				System.out.println(nomes);
			}
			br.close();
		}catch(IOException exc){
			System.err.println("Erro de Entrada e Saida (I/O): " + exc);
		}
	}
}