# AI 与代码贡献规则（仓库级）

目的：规范代码风格、贡献流程，并让 AI 在每次会话中遵循自动更新分类的触发规则。

1. 代码风格
- 语言：C++（目标标准为 `C++17`）。
- 编译：提交前应能用 `g++ -std=c++17 -O2 -pipe` 编译通过（示例在 `README.md` 中）。
- 文件编码：UTF-8（无 BOM）。
- 缩进：4 个空格或根据 `.editorconfig` 的设置。
- 提倡使用仓库 `template.cpp` 中的常用宏/风格（例如 `using namespace std;`）。

2. 文件与命名
- 按平台目录放置题目代码：`Atcoder/`、`luogu/`、`nowcoder/` 等。
- 文件名尽量使用题目编号或短名，避免空格（示例：`P16426.cpp`，而非 `P16426 .cpp`）。

3. 提交与 PR 要求
- 提交前自测通过样例；PR 描述请包含题目来源、题目编号及难度（可选）。
- 若包含多个题目，建议每个题目单独提交（便于回溯）。

4. 完成题目的自动更新触发器（必须遵守）
- 会话触发：在与 AI 的会话中发送一条消息，格式为：
  - `已完成: <相对路径>` 例如 `已完成: luogu/P16425.cpp`。
- 文件注释触发：在代码文件顶部添加注释 `// SOLVED`（assistant 会在会话中检测并记录）。
- 触发后流程：assistant 会把条目加入 `/memories/session/types_cursor.md` 的待更新列表，并在你确认后将其同步到 `算法题分类.md`。

5. AI 行为规范（对 assistant 的期望）
- 每次会话开始时，assistant 应读取 `/memories/repo/assistant_rules.md`（仓库规则）与 `/memories/session/types_cursor.md`（会话待更新）并遵循其中规则。
- assistant 在检测到 `已完成:` 触发后，会：
  1. 在会话中回应并确认该路径是否正确。
  2. 给出分类建议（基于文件内容和已有标签）。
  3. 等待用户确认后把条目写入 `算法题分类.md`。

6. 自动化与检查（可选）
- 建议在本机/CI 中加入 `clang-format` 或 `pre-commit` 钩子以保证风格一致。

7. 变更此规则
- 修改 `AI_RULES.md` 会在下一次会话被 assistant 读取并遵循。若需要 assistant 主动同步到 `/memories/repo/assistant_rules.md`，请在会话中指示 “保存规则”。

---

需要我现在把这份规则保存到仓库根目录并同步到 repo memory 吗？（已为你准备好，正在写入）