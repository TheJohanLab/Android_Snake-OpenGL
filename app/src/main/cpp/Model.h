#ifndef ANDROIDGLINVESTIGATIONS_MODEL_H
#define ANDROIDGLINVESTIGATIONS_MODEL_H

#include <vector>
#include "TextureAsset.h"

union Vector4 {
    struct {
        float x, y, z, w;
    };
    float idx[4];
};

union Vector3 {
    struct {
        float x, y, z;
    };
    float idx[3];
};

union Vector2 {
    struct {
        float x, y;
    };
    struct {
        float u, v;
    };
    float idx[2];
};

struct Vertex {
    constexpr Vertex(const Vector3 &inPosition, const Vector4 &inUV) : position(inPosition),
                                                                       uv(inUV) {}
    Vertex() {}

    Vector3 position;
    Vector4 uv;
};

struct Quad
{
    Quad() {

    }

    Vertex vertex1;
    Vertex vertex2;
    Vertex vertex3;
    Vertex vertex4;
};

typedef uint16_t Index;

class Model {
public:
    inline Model(
            std::vector<Quad> vertices,
            std::vector<Index> indices,
            std::shared_ptr<TextureAsset> spTexture)
            : vertices_(std::move(vertices)),
              indices_(std::move(indices)),
              spTexture_(std::move(spTexture))
              {}

    inline const Quad *getVertexData() const {
        return vertices_.data();
    }

    inline const size_t getIndexCount() const {
        return indices_.size();
    }

    inline const Index *getIndexData() const {
        return indices_.data();
    }

    inline const TextureAsset &getTexture() const {
        return *spTexture_;
    }

    inline void updateVertex(int x, int y, Vector4 color)
    {
        int idx = x + y * 20;
        //Vector4 color = {1.0, 1.0, 1.0, 1.0};
        vertices_[idx].vertex1.uv = color;
        vertices_[idx].vertex2.uv = color;
        vertices_[idx].vertex3.uv = color;
        vertices_[idx].vertex4.uv = color;
    }

    inline std::vector<Quad> getVertices() const
    {
        return vertices_;
    }

private:
    std::vector<Quad> vertices_;
    std::vector<Index> indices_;
    std::shared_ptr<TextureAsset> spTexture_;
};

#endif //ANDROIDGLINVESTIGATIONS_MODEL_H