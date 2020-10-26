public class Triangulo extends TwoDShape {
    private String estilo;
    
    public void setEstilo(String estilo){
    	this.estilo = estilo;
    }

    public void mostraEstilo() {
       System.out.println("Triangulo = " + estilo);
    }

    public double area() {
    	return (getLargura() * getAltura()) / 2;
    }
}