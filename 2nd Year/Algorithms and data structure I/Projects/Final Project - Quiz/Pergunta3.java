����   9 �  	Pergunta3  javax/swing/JFrame  java/awt/event/ActionListener fonte Ljava/awt/Font; escolhas [Ljavax/swing/JButton; imagem Ljavax/swing/ImageIcon; label Ljavax/swing/JLabel; texto texto1 texto2 <init> ()V Code
      java/awt/Font  Arial
     (Ljava/lang/String;II)V	     ! javax/swing/JButton	  # 	 
 % javax/swing/ImageIcon
 ' ) ( java/lang/Object * + getClass ()Ljava/lang/Class; - /Imagens/pergunta3.png
 / 1 0 java/lang/Class 2 3 getResource "(Ljava/lang/String;)Ljava/net/URL;
 $ 5  6 (Ljava/net/URL;)V	  8   : javax/swing/JLabel
 9 <  = (Ljavax/swing/Icon;)V	  ?  
 9 	  B  	  D  	  F   H A
   J  K (Ljava/lang/String;)V M B O C Q D
 9 S T U 	setBounds (IIII)V
 9 W X Y setFont (Ljava/awt/Font;)V [ N3 - Qual é o método de ordenação que se baseia no conceito de dividir para
 9 ] ^ K setText
  ` a b add *(Ljava/awt/Component;)Ljava/awt/Component; d ?conquistar e é o mais utilizado e o mais rápido em uma grande f diversidade de situações?
  h i j 	setLayout (Ljava/awt/LayoutManager;)V
   W
   S n 
Pergunta 3
  p q K setTitle
  s t u setSize (II)V
  w x y setDefaultCloseOperation (I)V
  { | } setResizable (Z)V
   � � setLocationRelativeTo (Ljava/awt/Component;)V
  � � } 
setVisible LineNumberTable LocalVariableTable this LPergunta3; i I StackMapTable setAlternativas K(Ljava/lang/String;Ljava/lang/String;Ljava/lang/String;Ljava/lang/String;)V
   � � � addActionListener "(Ljava/awt/event/ActionListener;)V
   ] altA Ljava/lang/String; altB altC altD actionPerformed (Ljava/awt/event/ActionEvent;)V
 � � � java/awt/event/ActionEvent � � 	getSource ()Ljava/lang/Object;
  � �  dispose
  � �  mensagem � 	Pergunta4
 �  � Lista Ligada Simples � Lista Ligada Circular � Lista Duplamente Ligada � 1<html>Lista Duplamente <br>Ligada Circular</html>
 � � � � � *Infelizmente Você Errou!
Tente novamente. � Quiz
 � � � javax/swing/JOptionPane � � showMessageDialog <(Ljava/awt/Component;Ljava/lang/Object;Ljava/lang/String;I)V
 � � � java/lang/System � y exit e Ljava/awt/event/ActionEvent; 	pergunta4 LPergunta4; � Parabéns! Você Acertou 
SourceFile Pergunta3.java !              	 
                                        �    �*� *� Y� � *�  � "*� $Y*� &,� .� 4� 7*� 9Y*� 7� ;� >*� 9Y� @� A*� 9Y� @� C*� 9Y� @� E*� "�  YG� IS*� "�  YL� IS*� "�  YN� IS*� "�  YP� IS*� AX� R*� A*� � V*� AZ� \**� A� _W*� C-X� R*� C*� � V*� Cc� \**� C� _W*� EF�� R*� E*� � V*� Ee� \**� E� _W*� >dd� ȶ R**� >� _W*� g<� *� "2*� � k�*� "����*� "2(J,d� l*� "2^J,d� l*� "2(�,d� l*� "2^�,d� l*m� o*�X� r*� v*� z*� ~*� ��    �   � )          0  ?  J  U  `  o  ~  �  �  �  �   � ! � # � $ � % � & � ( ) * +# -4 .= 0B 2G 3T 2` 6s 7� 8� 9� ;� <� =� >� ?� @� B �      � � �  D  � �  �    �G      � �         g6� *� "2*� ��*� "����*� "2+� �*� "2,� �*� "2-� �*� "2� �6� **� "2� _W�*� "����    �   .    F  G  F  J ( K 2 L < M G O M P Y O f R �   H    g � �     g � �    g � �    g � �    g � �    � �  J  � �  �   	 � 8  � �     �     :+� �*� "2� "*� �*� �� �Y� �M,����� �� ��� �� ��    �   .    U  V  W  X  Y " Z & Y ) [ , \ 5 ] 9 _ �        : � �     : � �    � �  �    ,  �      8     
��� ��    �   
    b 	 c �       
 � �    �    �