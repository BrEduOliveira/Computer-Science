public class Retangulo extends TwoDShape {
  
    public double area() {
        return getLargura() * getAltura();
    }

    public Boolean quadrado(){
        if (getLargura() == getAltura()){
            return true;
        }else{
            return false;
        }
    }

}