    if (packet.find("game_version|") != -1) {
        rtvar var = rtvar::parse(packet);
        auto mac = utils::generate_mac();
        auto hash_str = mac + "RT";
        auto hash2 = utils::hash((uint8_t*)hash_str.c_str(), hash_str.length());
        var.set("mac", mac);
        var.set("wk", utils::generate_rid());
        var.set("rid", utils::generate_rid());
        var.set("fz", std::to_string(utils::random(INT_MIN, INT_MAX)));
        var.set("zf", std::to_string(utils::random(INT_MIN, INT_MAX)));
        var.set("hash", std::to_string(utils::random(INT_MIN, INT_MAX)));
        var.set("hash2", std::to_string(hash2));
        var.set("meta", "");
        var.set("game_version", gt::version);
        var.set("country", gt::flag);
        var.find("platformID")->m_values[0] = "4"; 
        var.remove("fz");
        var.remove("rid");
         }

        packet = var.serialize();
        gt::in_game = false;
        PRINTS("Spoofing login info\n");
        g_server->send(false, packet);
        return true;
    }

    return false;
}



