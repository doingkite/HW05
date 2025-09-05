// Fill out your copyright notice in the Description page of Project Settings.

#include "MyActor.h"

// Sets default values
AMyActor::AMyActor()
{
    // Set this actor to call Tick() every frame.  
    // You can turn this off to improve performance if you don't need it.
    PrimaryActorTick.bCanEverTick = false;

    // ������ (0,0) �ʱ�ȭ
    CurrentLocation = FVector2D(0, 0);
    PreviousLocation = FVector2D(0, 0);
    TotalDistance = 0.f;
    TotalEventCount = 0;
}

// Called when the game starts or when spawned
void AMyActor::BeginPlay()
{
    Super::BeginPlay();

    // ���� ��ǥ ���
    UE_LOG(LogTemp, Warning, TEXT("Initial Location: (%f, %f)"), CurrentLocation.X, CurrentLocation.Y);

    // 10ȸ �̵�
    Move(10, 50);
}

// Called every frame
void AMyActor::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);
}

// Step �Լ�: 0 �Ǵ� 1 ��ȯ
int32 AMyActor::Step() {
    return FMath::RandRange(0, 1);
}

// Move �Լ�: MoveCount ��ŭ �̵�
void AMyActor::Move(int32 MoveCount, float Proability)
{
    for (int32 i = 0; i < MoveCount; ++i)
    {
        PreviousLocation = CurrentLocation;
        // x, y ��ǥ ���� step ����
        CurrentLocation.X += Step();
        CurrentLocation.Y += Step();

        TriggerEventWithProability(Proability);
        // == Move(int32 MoveCount, float Proability) -->   TriggerEventWithProability(proability)  
        //---> ����÷����� ���� Move(10, 50) ���� �ٲ��ִ� �Ͱ� ����

        //�̵��Ÿ� ���ϱ�
        float MovedDistance = Distance(CurrentLocation, PreviousLocation);
        TotalDistance += MovedDistance;
        // ���� ��ǥ ���
        UE_LOG(LogTemp, Warning, TEXT("Step %d Location: (%f, %f), Moved Distance: %f "), i + 1, CurrentLocation.X, CurrentLocation.Y, MovedDistance);
    }
    // 10ȸ �̵� �� �� �̵��Ÿ��� �� �̺�Ʈ �߻�Ƚ�� ���
        UE_LOG(LogTemp, Warning, TEXT("Total Distance: %f,  Total Event Count: %d"), TotalDistance, TotalEventCount);

}

void AMyActor::TriggerEventWithProability(float Proability)
{
    //����Ȯ�� 50���� �̺�Ʈ �߻�, �� ���ܸ��� �̺�Ʈ �߻����� ���
    int32 RandomValue = FMath::RandRange(1, 100);
    //�̺�Ʈ ��÷ ���� Ȯ�� ���?
    //1~50: ��÷ 51~100: ��÷
    if (RandomValue <= Proability) {
         //��÷
        UE_LOG(LogTemp, Warning, TEXT("Event Occured"));
        ++TotalEventCount;
    }   //��÷
    else {
        UE_LOG(LogTemp, Warning, TEXT("Event Not Occured"));
    }
}

float AMyActor::Distance(FVector2D second, FVector2D first)
{
    float dx = second.X - first.X;
    float dy = second.Y - first.Y;
    //dx*dx + dy*dy
    return FMath::Sqrt(FMath::Square(dx) + FMath::Square(dy)); 
    
}


