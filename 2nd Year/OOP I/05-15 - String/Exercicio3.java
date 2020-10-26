public class Exercicio3 {
	public static void main(String args[]) {
		String s = "Computacao";

		if(processar(s) == "Nulo"){
			System.out.println("String nula");
		}else{
			System.out.println(processar(s));
		}
		
		s = "";

		if(processar(s) == "Nulo"){
			System.out.println("String nula");
		}else{
			System.out.println(processar(s));
		}

		s = "programacao";

		if(processar(s) == "Nulo"){
			System.out.println("String nula");
		}else{
			System.out.println(processar(s));
		}

	}

	public static String processar(String frase) {

		if(frase == null || frase.isEmpty()){
			return "Nulo";
		}else{
			return frase.toUpperCase();
		}
	}
}