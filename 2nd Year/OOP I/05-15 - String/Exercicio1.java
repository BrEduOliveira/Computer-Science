public class Exercicio1 {
	public static void main(String args[]) {
		verificar("Computacao");
		verificar("Mouse");
	}

	public static void verificar(String frase) {
		String word;
		String word1;

		if(frase.length() < 8){
			System.out.println("Frase com menos de 8 caracteres!");
		}else{
			word = frase.substring(0,2) + frase.substring(frase.length()-2,frase.length());
			System.out.println(word);
		}
	}
}
