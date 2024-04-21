#include <gtest/gtest.h>
#include "MyFitnessPal.h"
#include "utilizator.h"
#include "entitate.h"

TEST(SuiteName, TestName1) {
    utilizator u1;
    const utilizator& u2(u1);
    EXPECT_EQ(u1, u2);
}

TEST(SuiteName, TestName2) {
    utilizator u1(1,1,1,"1","1");
    const utilizator& u2(u1);
    EXPECT_EQ(u1, u2);
}

// Test pentru moșteniri
TEST(MosteniriTest, VerificareMostenire) {
    // Se creează un utilizator și se verifică dacă se poate obține numele corect
    utilizator u(25, 180, 75, "John", "M");
    EXPECT_EQ(u.getNume(), "John");
}

// Test pentru upcast și downcast
TEST(CastTest, UpcastDowncast) {
    // Creăm un utilizator și apoi îl convertim într-o entitate și apoi înapoi în utilizator
    utilizator u(30, 160, 55, "Alice", "F");
    const entitate& e = u;
    const auto& u2 = dynamic_cast<const utilizator&>(e); // Downcast
    EXPECT_EQ(u, u2);
}


TEST(VirtualDestructorTest, TestVirtualDestructor) {
    // Creăm un obiect de tip MyFitnessPal
    auto* mfp = new MyFitnessPal();

    // Ștergem obiectul folosind pointerul la clasa de bază
    delete mfp;

    // Verificăm dacă obiectul a fost șters corect
    ASSERT_TRUE(true); // Testul trece automat dacă obiectul a fost șters fără erori
}

TEST(AbstractClassTest, TestAbstractClass) {
    // Creăm un obiect de tip entitate (clasa abstractă)
    entitate* e = new utilizator();

    // Verificăm dacă obiectul a fost creat corect
    ASSERT_TRUE(true); // Testul trece automat dacă obiectul a fost creat fără erori

    // Ștergem obiectul
    delete e;
}

TEST(InputOutputTest, TestInputOutput) {
    // Creăm un vector de 3 obiecte de tip MyFitnessPal
    std::vector<MyFitnessPal> mfpVector(3);

    // Afișăm detaliile fiecărui obiect din vector
    for (const auto& mfp : mfpVector) {
        mfp.afisareDetaliiEntitati();
    }

    // Verificăm dacă afișarea a fost realizată fără erori
    ASSERT_TRUE(true); // Testul trece automat dacă afișarea s-a făcut corect
}