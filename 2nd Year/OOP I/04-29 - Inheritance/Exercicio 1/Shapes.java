public class Shapes {
  public static void main(String[] args) {
     Triangulo t1 = new Triangulo();
     Triangulo t2 = new Triangulo();
     Retangulo r1 = new Retangulo();

     t1.setLargura(4.0);
     t1.setAltura(4.0);
     t1.setEstilo("cheio");

     t2.setLargura(8.0);
     t2.setAltura(12.0);
     t2.setEstilo("contorno");

     r1.setLargura(5.0);
     r1.setAltura(4.0);

     System.out.println("Info para t1: ");
     t1.mostraEstilo();
     t1.mostraDim();
     System.out.println("Area = " + t1.area());
     System.out.println();

     System.out.println("Info para t2: ");
     t2.mostraEstilo();
     t2.mostraDim();
     System.out.println("Area = " + t2.area());
     System.out.println();

     System.out.println("Info para r1: ");
     r1.mostraDim();
     System.out.println("Area = " + r1.area());
     if (r1.quadrado()){
     	System.out.println("E um quadrado!");
     }else{
     	System.out.println("Nao e um quadrado!");
     }
   }
}