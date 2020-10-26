public class Exercicio2 {
	public static void main(String args[]) {
		verificar("Computacao", "computacao");
		verificar("Mouse", "Teclado");
		verificar("Programacao", "Programacao");
	}

	public static void verificar(String frase, String frase1) {

		if(frase.equals(frase1)){
			System.out.println("Sao iguais!");	
		}else if(frase.equalsIgnoreCase(frase1)){
			System.out.println("Sao iguais ignorando maiusculas e minusculas!");
		}else{
			System.out.println("Nao sao iguais!");
		}
	}
}
