����   9 �  	Pergunta2  javax/swing/JFrame  java/awt/event/ActionListener fonte Ljava/awt/Font; escolhas [Ljavax/swing/JButton; imagem Ljavax/swing/ImageIcon; label Ljavax/swing/JLabel; texto texto1 <init> ()V Code
      java/awt/Font  Arial
     (Ljava/lang/String;II)V	       javax/swing/JButton	  " 	 
 $ javax/swing/ImageIcon
 & ( ' java/lang/Object ) * getClass ()Ljava/lang/Class; , /Imagens/pergunta2.png
 . 0 / java/lang/Class 1 2 getResource "(Ljava/lang/String;)Ljava/net/URL;
 # 4  5 (Ljava/net/URL;)V	  7   9 javax/swing/JLabel
 8 ;  < (Ljavax/swing/Icon;)V	  >  
 8 	  A  	  C   E A
  G  H (Ljava/lang/String;)V J B L C N D
 8 P Q R 	setBounds (IIII)V
 8 T U V setFont (Ljava/awt/Font;)V X 52 - Qual estrutura de dados em que o último elemento
 8 Z [ H setText
  ] ^ _ add *(Ljava/awt/Component;)Ljava/awt/Component; a Fque entra é o primeiro que sai, ou seja, é LIFO(last-in, first-out)?
  c d e 	setLayout (Ljava/awt/LayoutManager;)V
  T
  P i 
Pergunta 2
  k l H setTitle
  n o p setSize (II)V
  r s t setDefaultCloseOperation (I)V
  v w x setResizable (Z)V
  z { | setLocationRelativeTo (Ljava/awt/Component;)V
  ~  x 
setVisible LineNumberTable LocalVariableTable this LPergunta2; i I StackMapTable setAlternativas K(Ljava/lang/String;Ljava/lang/String;Ljava/lang/String;Ljava/lang/String;)V
  � � � addActionListener "(Ljava/awt/event/ActionListener;)V
  Z altA Ljava/lang/String; altB altC altD actionPerformed (Ljava/awt/event/ActionEvent;)V
 � � � java/awt/event/ActionEvent � � 	getSource ()Ljava/lang/Object;
  � �  dispose
  � �  mensagem � 	Pergunta3
 �  � 
Bubblesort � 
Buckersort � 	Quicksort � 	Radixsort
 � � � � � *Infelizmente Você Errou!
Tente novamente. � Quiz
 � � � javax/swing/JOptionPane � � showMessageDialog <(Ljava/awt/Component;Ljava/lang/Object;Ljava/lang/String;I)V
 � � � java/lang/System � t exit e Ljava/awt/event/ActionEvent; 	pergunta3 LPergunta3; � Parabéns! Você Acertou 
SourceFile Pergunta2.java !              	 
                                  o    �*� *� Y� � *� � !*� #Y*� %+� -� 3� 6*� 8Y*� 6� :� =*� 8Y� ?� @*� 8Y� ?� B*� !� YD� FS*� !� YI� FS*� !� YK� FS*� !� YM� FS*� @�� O*� @*� � S*� @W� Y**� @� \W*� B-�� O*� B*� � S*� B`� Y**� B� \W*� =dd� ȶ O**� =� \W*� b<� *� !2*� � f�*� !����*� !2(J,d� g*� !2^J,d� g*� !2(�,d� g*� !2^�,d� g*h� j*�X� m*� q*� u*� y*� }�    �   � $          0  ?  J  U  d  s  �  �  �  �  �   � " � # � $ � % � ' � ( *
 , - ,( 0; 1O 2b 3v 5| 6� 7� 8� 9� :� < �      � � �    � �  �    �      � �         g6� *� !2*� ��*� !����*� !2+� �*� !2,� �*� !2-� �*� !2� �6� **� !2� \W�*� !����    �   .    @  A  @  D ( E 2 F < G G I M J Y I f L �   H    g � �     g � �    g � �    g � �    g � �    � �  J  � �  �   	 � 8  � �     �     :+� �*� !2� "*� �*� �� �Y� �M,����� �� ��� �� ��    �   & 	   O  P  Q  R  S ) T , U 5 V 9 Y �        : � �     : � �    � �  �    ,  �      8     
��� ��    �   
    \ 	 ] �       
 � �    �    �