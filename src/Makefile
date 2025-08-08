# コンパイラとフラグ
CXX = g++
CXXFLAGS = -std=c++11 -Wall -O3 -MMD -MP 
CPPFLAGS = -I$(SRCDIR)/include

# ディレクトリとターゲット名
SRCDIR = code
BUILDDIR = build
TARGET = my_app

# code/ 配下のすべての .cpp ファイルを再帰的に取得
SRCS := $(shell find $(SRCDIR) -name '*.cpp')

# .cppファイルのベース名（ディレクトリを除去）を取得
BASES := $(notdir $(SRCS))

# オブジェクトファイル（build/Vec.o など）に変換
OBJS := $(addprefix $(BUILDDIR)/,$(BASES:.cpp=.o))
DEPS := $(OBJS:.o=.d)

# デフォルトターゲット
all: $(TARGET)

# 実行ファイルのリンク
$(TARGET): $(OBJS)
	$(CXX) -o $@ $^ -fopenmp

# vpath を使って各 cpp ファイルを探せるようにする
vpath %.cpp $(sort $(dir $(SRCS)))

# .cpp から .o へのビルドルール（build直下に集約）
$(BUILDDIR)/%.o: %.cpp
	@mkdir -p $(BUILDDIR)
	$(CXX) $(CXXFLAGS) $(CPPFLAGS) -c $< -o $@

# クリーンアップ
clean:
	rm -rf $(BUILDDIR)
	rm -f $(TARGET)

# 依存関係の読み込み（初回は -include によって無視される）
-include $(DEPS)

.PHONY: all clean
