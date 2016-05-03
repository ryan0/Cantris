Spatial = {
    position = {0, 0}
}

Physical = {
    b2BodyDef = {
        position = {39.3, 49.2},
        type = "b2_staticBody"
    },

    b2FixtureDef = {
        friction = .3,
        restitution = 0.0,
        b2PolygonShape = {
            setAsBox = {10, 0.8}
        }
    }
}