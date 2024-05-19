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


TEST(MosteniriTest, VerificareMostenire) {
    utilizator u(25, 180, 75, "John", "M");
    EXPECT_EQ(u.getNume(), "John");
}


TEST(CastTest, UpcastDowncast) {
    utilizator u(30, 160, 55, "Alice", "F");
    const entitate& e = u;
    const auto& u2 = dynamic_cast<const utilizator&>(e); // Downcast
    EXPECT_EQ(u, u2);
}


TEST(VirtualDestructorTest, TestVirtualDestructor) {
    auto* mfp = new MyFitnessPal();
    delete mfp;
    ASSERT_TRUE(true);
}

TEST(AbstractClassTest, TestAbstractClass) {
    entitate* e = new utilizator();
    ASSERT_TRUE(true);
    delete e;
}

TEST(InputOutputTest, TestInputOutput) {
    std::vector<MyFitnessPal> mfpVector(3);
    for (const auto& mfp : mfpVector) {
        mfp.afisareDetaliiEntitati();
    }
    ASSERT_TRUE(true);
}