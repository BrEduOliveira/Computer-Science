����   9 �  	Pergunta4  javax/swing/JFrame  java/awt/event/ActionListener fonte Ljava/awt/Font; escolhas [Ljavax/swing/JButton; imagem Ljavax/swing/ImageIcon; label Ljavax/swing/JLabel; texto <init> ()V Code
      java/awt/Font  Arial
     (Ljava/lang/String;II)V	      javax/swing/JButton	  ! 	 
 # javax/swing/ImageIcon
 % ' & java/lang/Object ( ) getClass ()Ljava/lang/Class; + /Imagens/pergunta4.png
 - / . java/lang/Class 0 1 getResource "(Ljava/lang/String;)Ljava/net/URL;
 " 3  4 (Ljava/net/URL;)V	  6   8 javax/swing/JLabel
 7 :  ; (Ljavax/swing/Icon;)V	  =  
 7 	  @   B A
  D  E (Ljava/lang/String;)V G B I C K D
 7 M N O 	setBounds (IIII)V
 7 Q R S setFont (Ljava/awt/Font;)V U 54 - Qual estrutura de dados é apresentada na figura?
 7 W X E setText
  Z [ \ add *(Ljava/awt/Component;)Ljava/awt/Component;
  ^ _ ` 	setLayout (Ljava/awt/LayoutManager;)V
  Q
  M d 
Pergunta 4
  f g E setTitle
  i j k setSize (II)V
  m n o setDefaultCloseOperation (I)V
  q r s setResizable (Z)V
  u v w setLocationRelativeTo (Ljava/awt/Component;)V
  y z s 
setVisible LineNumberTable LocalVariableTable this LPergunta4; i I StackMapTable setAlternativas K(Ljava/lang/String;Ljava/lang/String;Ljava/lang/String;Ljava/lang/String;)V
  � � � addActionListener "(Ljava/awt/event/ActionListener;)V
  W altA Ljava/lang/String; altB altC altD actionPerformed (Ljava/awt/event/ActionEvent;)V
 � � � java/awt/event/ActionEvent � � 	getSource ()Ljava/lang/Object;
  � �  dispose
  � �  mensagem � 	Pergunta5
 �  � Pilha � Fila � 	Quicksort � Stack
 � � � � � *Infelizmente Você Errou!
Tente novamente. � Quiz
 � � � javax/swing/JOptionPane � � showMessageDialog <(Ljava/awt/Component;Ljava/lang/Object;Ljava/lang/String;I)V
 � � � java/lang/System � o exit e Ljava/awt/event/ActionEvent; 	pergunta5 LPergunta5; � Parabéns! Você Acertou 
SourceFile Pergunta4.java !              	 
                            #    c*� *� Y� � *� �  *� "Y*� $*� ,� 2� 5*� 7Y*� 5� 9� <*� 7Y� >� ?*�  � YA� CS*�  � YF� CS*�  � YH� CS*�  � YJ� CS*� ?�� L*� ?*� � P*� ?T� V**� ?� YW*� <(dX ȶ L**� <� YW*� ]<� *�  2*� � a�*�  ����*�  2(J,d� b*�  2^J,d� b*�  2(�,d� b*�  2^�,d� b*c� e*�X� h*� l*� p*� t*� x�    {   ~           0  ?  J  Y  h  w  �  �  �  �  � ! � " � $ � & � ' � & � * + ,* -> /D 0N 1S 2X 3] 4b 6 |      c } ~   �   �  �    � �      � �         g6� *�  2*� ��*�  ����*�  2+� �*�  2,� �*�  2-� �*�  2� �6� **�  2� YW�*�  ����    {   .    :  ;  :  > ( ? 2 @ < A G C M D Y C f F |   H    g } ~     g � �    g � �    g � �    g � �     �  J   �  �   	 � 8  � �     �     :+� �*�  2� "*� �*� �� �Y� �M,����� �� ��� �� ��    {   & 	   I  J  K  L  M ) N , O 5 P 9 S |        : } ~     : � �    � �  �    ,  �      8     
��� ��    {   
    V 	 W |       
 } ~    �    �