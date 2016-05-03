Renderable = {
    zValue = 0,
    position = {-1.0, -1.0}
}

Graphical = {
    texture = "demo/wood.png",
    textureRect = {0, 0, 4, 4 },
}

Spatial = {
    position = {0, 0}
}

Movable = {
    velocity = {0, 0}
}


Physical = {
    b2BodyDef = {
        position = {10, 36},
        type = "b2_dynamicBody"
    },

    b2FixtureDef = {
        density = 1.0,
        friction = .3,
        restitution = .1,
        b2PolygonShape = {
                setAsBox = {1.0, 1.0}
        }
    }
}