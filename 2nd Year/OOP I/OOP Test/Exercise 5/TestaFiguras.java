public class TestaFiguras{
	public static void main(String[] args) {
		Figura[] figuras = new Figura[3];
		
		figuras[0] = new Triangulo();
		figuras[1] = new Quadrado();
		figuras[2] = new Retangulo();

		for(int i=0; i<figuras.length; i++){
			figuras[i].desenhar();
			figuras[i].apagar();
		}

	}
}