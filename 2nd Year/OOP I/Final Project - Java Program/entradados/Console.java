package entradados;

import java.io.*;
import java.util.*;
//Importa o package personalização para deixar o programa mais bonito
import personalizacao.*;

public class Console {
	
	//Um objeto que chama a classe Personalizado para ajustar a interface do console
	Personalizado p = new Personalizado();
	
	//Atributo privado para o número de clientes (só pode ser acessado pelo método acessador)
	private int num;
	
	//Uma variavel que vai servir como um contador
	static int cont = 1;
		
	//Método que recebe o nome do cliente que o usuário digitar e retorna para a classe que chamou 
	//esse método
	public static String leitura() {
		try {
			BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
			
			System.out.printf("\nPor favor insira o nome do cliente %d: ", cont);
			
			cont++;
			
			return br.readLine();
			
		}catch(IOException e) {
			throw new RuntimeException("Erro ao ler o nome do cliente");
		}
	}
	
	//Método para determinar o número total de clientes que serão inseridos
	public void numeroClientes() {
		int n;
		boolean loop = true;
		Scanner scanner2 = new Scanner(System.in);
		
		//Tratamento de exceção para que o usuário digite apenas números
		try {
			//Método personalizado
			p.centro();
			
			System.out.printf("Insira o numero de clientes: ");
			
			n = scanner2.nextInt();
			
			//O método verifica() confere se o número de clientes não é maior que 10
			if(verifica(n)) {
				do {
					System.err.println("Ops!\nNao aceitamos mais que 10 clientes. Tente novamente!");
					numeroClientes();
					loop = false;
				}while(loop);
			}else{
				setMaxTamClientes(n);
			}
			
		//Caso o usuário digitar uma letra ao invés de um número
		}catch (InputMismatchException exc) {
			System.err.println("Ops!\nVoce digitou uma letra. Tente novamente!");
			numeroClientes();	
		}
	}
	
	//Método para verificar o número de clientes
	public boolean verifica(int n) {
		if(n>10) {
			return true;
		}else {
			return false;
		}
	}
	
	//Metodo acessador
	public int getMaxTamClientes() {
		return num;
	}
	
	//Metodo modificador
	public void setMaxTamClientes(int num) {
		this.num = num;
	}
}