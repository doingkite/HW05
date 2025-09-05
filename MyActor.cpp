// Fill out your copyright notice in the Description page of Project Settings.

#include "MyActor.h"

// Sets default values
AMyActor::AMyActor()
{
    // Set this actor to call Tick() every frame.  
    // You can turn this off to improve performance if you don't need it.
    PrimaryActorTick.bCanEverTick = false;

    // 시작점 (0,0) 초기화
    CurrentLocation = FVector2D(0, 0);
    PreviousLocation = FVector2D(0, 0);
    TotalDistance = 0.f;
    TotalEventCount = 0;
}

// Called when the game starts or when spawned
void AMyActor::BeginPlay()
{
    Super::BeginPlay();

    // 시작 좌표 출력
    UE_LOG(LogTemp, Warning, TEXT("Initial Location: (%f, %f)"), CurrentLocation.X, CurrentLocation.Y);

    // 10회 이동
    Move(10, 50);
}

// Called every frame
void AMyActor::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);
}

// Step 함수: 0 또는 1 반환
int32 AMyActor::Step() {
    return FMath::RandRange(0, 1);
}

// Move 함수: MoveCount 만큼 이동
void AMyActor::Move(int32 MoveCount, float Proability)
{
    for (int32 i = 0; i < MoveCount; ++i)
    {
        PreviousLocation = CurrentLocation;
        // x, y 좌표 각각 step 적용
        CurrentLocation.X += Step();
        CurrentLocation.Y += Step();

        TriggerEventWithProability(Proability);
        // == Move(int32 MoveCount, float Proability) -->   TriggerEventWithProability(proability)  
        //---> 비긴플레이의 변수 Move(10, 50) 으로 바꿔주는 것과 같다

        //이동거리 구하기
        float MovedDistance = Distance(CurrentLocation, PreviousLocation);
        TotalDistance += MovedDistance;
        // 현재 좌표 출력
        UE_LOG(LogTemp, Warning, TEXT("Step %d Location: (%f, %f), Moved Distance: %f "), i + 1, CurrentLocation.X, CurrentLocation.Y, MovedDistance);
    }
    // 10회 이동 후 총 이동거리와 총 이벤트 발생횟수 출력
        UE_LOG(LogTemp, Warning, TEXT("Total Distance: %f,  Total Event Count: %d"), TotalDistance, TotalEventCount);

}

void AMyActor::TriggerEventWithProability(float Proability)
{
    //랜덤확률 50프로 이벤트 발생, 각 스텝마다 이벤트 발생여부 출력
    int32 RandomValue = FMath::RandRange(1, 100);
    //이벤트 당첨 여부 확인 방법?
    //1~50: 당첨 51~100: 낙첨
    if (RandomValue <= Proability) {
         //당첨
        UE_LOG(LogTemp, Warning, TEXT("Event Occured"));
        ++TotalEventCount;
    }   //낙첨
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


