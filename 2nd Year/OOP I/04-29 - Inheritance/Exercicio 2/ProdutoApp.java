public class ProdutoApp{
	public static void main(String[] args) {
		Produto produto = new Produto("livro", 50.00);
		Livro livro = new Livro(250, "Robert Kiyosaki", 40.00, "Pai rico, Pai pobre");

		livro.print();
		System.out.printf("Autor: %s\n\n", livro.getAutor());
		livro.setAutor("Caio Carneiro");
		System.out.println("Autor do livro alterado: " + livro.getAutor());
		System.out.printf("Preco reajustado em 20 porcento: %.2f \n", livro.getReajuste());
		if(livro.isCaro())
			System.out.println("O livro e caro");
		else
			System.out.println("O livro e barato");
		livro.print(250);
		System.out.println();
		if(livro.isExtenso())
			System.out.println("O livro tem muitas paginas");
		else
			System.out.println("O livro tem poucas paginas");

	}
}