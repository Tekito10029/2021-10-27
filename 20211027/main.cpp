#include <stdio.h>
#include <iostream>

/*
仮想関数
継承元のクラスの関数を仮想関数にしておくと、
継承先で処理を書き換えることができる。

// 仮想関数にしない場合
class ParentClass
{
public:
    ParentClass() {}
    void Print(){ printf("Parent\n"); }
};
class ChildClass : public ParentClass
{
public:
    ChildClass() {}
    void Print(){ printf("Child\n"); }
};
*/
/*
class ParentClass
{
public:
    ParentClass() {}
    void Print() { printf("Parent\n"); }
};
class ChildClass : public ParentClass
{
public:
    void Print() { printf("Child\n"); }
};

int main()
{
    ParentClass* parent = new ParentClass();
    ParentClass* child = new ChildClass();

    parent->Print();
    child->Print();

    delete parent;
    delete child;
}
*/
/*
上記のように、
ParentClass型に入れているので、
当然ParentClassの処理が呼び出される。
そのため、Printの内容はParentとなる。
仮想関数にすると同じ処理でも、
継承先の処理が行われるようになる。
そのためには、virtualをつけることで実現する。

class ParentClass
{
public:
    ParentClass() {}
    virtual void Print(){ printf("Parent\n"); }
};
class ChildClass : public ParentClass
{
public:
    ChildClass() {}
    void Print(){ printf("Child\n"); }
};
*/
/*
class ParentClass
{
public:
    ParentClass() {}
    virtual void Print() { printf("Parent\n"); }
};
class ChildClass : public ParentClass
{
public:
    void Print() { printf("Child\n"); }
};

int main()
{
    ParentClass* parent = new ParentClass();
    ParentClass* child = new ChildClass();

    parent->Print();
    child->Print();

    delete parent;
    delete child;
}

/*
クラスの型変換
継承したクラスというのは、継承元のクラスにキャストすることが可能です。
*/
/*
class Object
{
public:
    Object() {}
    virtual ~Object() { printf("Exec Object Destructor.\n"); }

public:
    virtual void Update() {}
};
class Player : public Object
{
public:
    Player() {}
    ~Player() { printf("Exec Player Destructor.\n"); }

public:
    void Update() { printf("Player Update\n"); }
};

int main()
{
    Player player;
    Object obj = static_cast<Object>(player);
    Object* objPointer = &player;

    // objPointerとplayerは同じ結果が出る。Object側がvirtualになっているから。
    // それはplayerを指すポインタを作成しているだけなので、
    // 実体はplayerのまま。
    // static_castで型変換をした、objはObjectの実体になっているので、
    // Player側で更新されたUpdateの処理を知る由もない。

    player.Update();
    obj.Update();
    objPointer->Update();
}
*/

/*
上記のように、staic_castを使用して、
PlayerクラスをObjectクラスに型変換しています。
その場合、PlayerクラスをObjectクラスに変換しているので、
最終的な実体はObjectクラスになっています。
(playerとobjは別物)

また、ポインタを使用して、Playerクラスのアドレスを、
Objectクラスのポインタに保存した場合は、
実体はPlayerのままなので、UpdateでPlayerの処理が呼ばれます。
(virtualをObjectにつけていない場合は、PlayerのUpdateが呼ばれません。)
継承先のPlayerクラスを継承元のObjectクラスにアドレスを保存できるのは、
PlayerクラスにはObjectクラスの情報があるからです。
(継承しているので持っていて当然。)
なので逆にObjectクラスをPlayerクラスに変換するのは、
危険なのでやってはいけません。
(ObjectクラスにはPlayerクラスに関する情報がない。)
*/

/*
【問題】
Objectクラス
x,y,z座標を保存する変数、Update関数を持つ。
Update関数はvirtualで作ってください。

Vehicle(乗り物)クラス
Objectクラスを継承したクラス。
ここではSpeedUpクラスを追加してください。
またspeedとaccelの変数をここで追加してください。
SpeedUpクラスはvirtualで作ってください。
(正確な速度の処理を行いたい場合は、向きと加速度で、
ベクトルを計算する方法でも構いません。)

Car(車)クラス
Vehicleクラスを継承したクラス
speedの変更をここでCar用に実装してください。

時間があれば、
Vehicleクラスを継承して、
bicycle(自転車)やbike(オートバイ)
といったクラスの作成や、
Carをさらに継承したpolice carや、truckなどの
クラスを作成してみてください。
*/

class Object
{
private:

public:
    virtual void Update()
    {
        int posX;
        int posY;
        int posZ;
    }
};

class Vehicele : public Object
{
private:
    int speed;
    int accel;

public:
    virtual void SpeedUp()
    {
        speed = accel + 1;
    }
};