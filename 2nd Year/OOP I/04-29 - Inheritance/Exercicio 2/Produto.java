public class Produto{
	protected String nome;
	protected double preco;

	public Produto(String oNome, double oPreco){
		nome = oNome;
		preco = oPreco;
	}

	public boolean isCaro(){
		if(preco > 50){
			return true;
		}else{
			return false;
		}
	}

	public double getReajuste(){
		preco += preco * 0.10;  
		return preco;   
  	}

  	public void print(){
    	System.out.printf("Livro: %s\nPreco: %.2f\n", nome, preco);
  	}

  	public void print(int paginas){
    	System.out.printf("Livro: %s\nPreco: %.2f\nPaginas: %d", nome, preco, paginas);
  	}
}