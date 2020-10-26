package principal;

//Importa todos os outros packages 
import entradados.*;
import personalizacao.Personalizado;
import cliente.*;
import arquivo.*;

public class ClienteApp{
	public static void main (String[] args) {
		
		//Um objeto que chama a classe Personalizado para ajustar a interface do console
		Personalizado p = new Personalizado();
		
		//Constante que vai armazenar o número de clientes
		final int tam;
		GerenciadorClientesArquivo gca = new GerenciadorClientesArquivo(); 
		Console console = new Console();
		
		p.menu();
		
		//Pede ao usuário digitar o número total de clientes que serão inseridos
		console.numeroClientes();
		
		//tam recebe esse número
		tam = console.getMaxTamClientes();
		
		//O array de clientes é finalmente criado e implementado
		Cliente[] cliente = new Cliente[tam];
		
		//Chama um método da classe Console onde serão inseridos os nomes dos clientes, e esses nomes
		//serão adicionados aos clientes na classe Cliente
		for (int i=0; i<tam; i++) {
			cliente[i] = new Cliente(console.leitura());
		}
		
		//Chama um método da classe GerenciadorClientesArquivo que vai gravar os nomes dos clientes
		//no arquivo clientes.txt
		gca.gravarClientes(cliente, tam);
		
		System.out.printf("\n------------------------------------------------\n\nLista de clientes:\n\n");
		
		//Imprime todos os nomes dos clientes contidos no arquivo clientes.txt criados na execução
		gca.lerClientes();
	}	
}