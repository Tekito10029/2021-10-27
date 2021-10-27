#include <stdio.h>
#include <iostream>

/*
���z�֐�
�p�����̃N���X�̊֐������z�֐��ɂ��Ă����ƁA
�p����ŏ��������������邱�Ƃ��ł���B

// ���z�֐��ɂ��Ȃ��ꍇ
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
��L�̂悤�ɁA
ParentClass�^�ɓ���Ă���̂ŁA
���RParentClass�̏������Ăяo�����B
���̂��߁APrint�̓��e��Parent�ƂȂ�B
���z�֐��ɂ���Ɠ��������ł��A
�p����̏������s����悤�ɂȂ�B
���̂��߂ɂ́Avirtual�����邱�ƂŎ�������B

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
�N���X�̌^�ϊ�
�p�������N���X�Ƃ����̂́A�p�����̃N���X�ɃL���X�g���邱�Ƃ��\�ł��B
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

    // objPointer��player�͓������ʂ��o��BObject����virtual�ɂȂ��Ă��邩��B
    // �����player���w���|�C���^���쐬���Ă��邾���Ȃ̂ŁA
    // ���̂�player�̂܂܁B
    // static_cast�Ō^�ϊ��������Aobj��Object�̎��̂ɂȂ��Ă���̂ŁA
    // Player���ōX�V���ꂽUpdate�̏�����m��R���Ȃ��B

    player.Update();
    obj.Update();
    objPointer->Update();
}
*/

/*
��L�̂悤�ɁAstaic_cast���g�p���āA
Player�N���X��Object�N���X�Ɍ^�ϊ����Ă��܂��B
���̏ꍇ�APlayer�N���X��Object�N���X�ɕϊ����Ă���̂ŁA
�ŏI�I�Ȏ��̂�Object�N���X�ɂȂ��Ă��܂��B
(player��obj�͕ʕ�)

�܂��A�|�C���^���g�p���āAPlayer�N���X�̃A�h���X���A
Object�N���X�̃|�C���^�ɕۑ������ꍇ�́A
���̂�Player�̂܂܂Ȃ̂ŁAUpdate��Player�̏������Ă΂�܂��B
(virtual��Object�ɂ��Ă��Ȃ��ꍇ�́APlayer��Update���Ă΂�܂���B)
�p�����Player�N���X���p������Object�N���X�ɃA�h���X��ۑ��ł���̂́A
Player�N���X�ɂ�Object�N���X�̏�񂪂��邩��ł��B
(�p�����Ă���̂Ŏ����Ă��ē��R�B)
�Ȃ̂ŋt��Object�N���X��Player�N���X�ɕϊ�����̂́A
�댯�Ȃ̂ł���Ă͂����܂���B
(Object�N���X�ɂ�Player�N���X�Ɋւ����񂪂Ȃ��B)
*/

/*
�y���z
Object�N���X
x,y,z���W��ۑ�����ϐ��AUpdate�֐������B
Update�֐���virtual�ō���Ă��������B

Vehicle(��蕨)�N���X
Object�N���X���p�������N���X�B
�����ł�SpeedUp�N���X��ǉ����Ă��������B
�܂�speed��accel�̕ϐ��������Œǉ����Ă��������B
SpeedUp�N���X��virtual�ō���Ă��������B
(���m�ȑ��x�̏������s�������ꍇ�́A�����Ɖ����x�ŁA
�x�N�g�����v�Z������@�ł��\���܂���B)

Car(��)�N���X
Vehicle�N���X���p�������N���X
speed�̕ύX��������Car�p�Ɏ������Ă��������B

���Ԃ�����΁A
Vehicle�N���X���p�����āA
bicycle(���]��)��bike(�I�[�g�o�C)
�Ƃ������N���X�̍쐬��A
Car������Ɍp������police car��Atruck�Ȃǂ�
�N���X���쐬���Ă݂Ă��������B
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