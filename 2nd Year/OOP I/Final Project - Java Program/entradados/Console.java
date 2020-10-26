package entradados;

import java.io.*;
import java.util.*;
//Importa o package personaliza��o para deixar o programa mais bonito
import personalizacao.*;

public class Console {
	
	//Um objeto que chama a classe Personalizado para ajustar a interface do console
	Personalizado p = new Personalizado();
	
	//Atributo privado para o n�mero de clientes (s� pode ser acessado pelo m�todo acessador)
	private int num;
	
	//Uma variavel que vai servir como um contador
	static int cont = 1;
		
	//M�todo que recebe o nome do cliente que o usu�rio digitar e retorna para a classe que chamou 
	//esse m�todo
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
	
	//M�todo para determinar o n�mero total de clientes que ser�o inseridos
	public void numeroClientes() {
		int n;
		boolean loop = true;
		Scanner scanner2 = new Scanner(System.in);
		
		//Tratamento de exce��o para que o usu�rio digite apenas n�meros
		try {
			//M�todo personalizado
			p.centro();
			
			System.out.printf("Insira o numero de clientes: ");
			
			n = scanner2.nextInt();
			
			//O m�todo verifica() confere se o n�mero de clientes n�o � maior que 10
			if(verifica(n)) {
				do {
					System.err.println("Ops!\nNao aceitamos mais que 10 clientes. Tente novamente!");
					numeroClientes();
					loop = false;
				}while(loop);
			}else{
				setMaxTamClientes(n);
			}
			
		//Caso o usu�rio digitar uma letra ao inv�s de um n�mero
		}catch (InputMismatchException exc) {
			System.err.println("Ops!\nVoce digitou uma letra. Tente novamente!");
			numeroClientes();	
		}
	}
	
	//M�todo para verificar o n�mero de clientes
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