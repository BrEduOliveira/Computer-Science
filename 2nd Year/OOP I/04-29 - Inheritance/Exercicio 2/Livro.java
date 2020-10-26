public class Livro extends Produto{
	private String autor;
	private int paginas;

	public Livro(int asPaginas, String oAutor, double oPreco, String oNome){
		super(oNome, oPreco);
		paginas = asPaginas;
		autor = oAutor;
	}

	public String getAutor(){
		return autor;
	}

	public void setAutor(String autor){
		this.autor = autor;
	}

	@Override
	public double getReajuste(){
		preco += preco * 0.20;
		return preco;
	}

	public boolean isExtenso(){
		if(paginas > 100){
			return true;
		}else{
			return false;
		}
	}

}